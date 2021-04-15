from flask_restful import reqparse, Resource
from .cors import CorsResource
from playhouse.shortcuts import model_to_dict
import json
import sys
sys.path.append('..')
import models


class RunList(CorsResource):
    def get(self):
        result = []
        i = 0
        for r in models.Run.select():
            dict_r = model_to_dict(r)
            dict_r['key'] = i
            i += 1
            result.append(dict_r)

        final_result = {"data":result}
        result_json = final_result
        return result_json, 200

    def post(self):
        parser = reqparse.RequestParser()
        parser.add_argument('rid', location='form', required=True)
        parser.add_argument('hashtag', location='form', required=True)
        parser.add_argument('target_path', location='form', required=True)
        parser.add_argument('count', type=int, location='form', required=True)
        parser.add_argument('scan_name', location='form', required=True)
        parser.add_argument('scan_date', location='form', required=True)
        parser.add_argument('scan_status', type=int, location='form', required=True)
        args = parser.parse_args()

        print(args)

        new_run = models.Run().create(
            scan_name=args['scan_name'],
            rid=args['rid'],
            hashtag=args['hashtag'],
            target_path=args['target_path'],
            count=args['count'],
            scan_date=args['scan_date'],
            scan_status=args['scan_status']
        )

        new_run.save()
        new_run_json = model_to_dict(new_run)

        return new_run_json, 201


class Run(CorsResource):
    def get(self, rid):
        r = models.Run.get(models.Run.rid == rid)
        r_json = model_to_dict(r)
        return r_json, 200

    def patch(self, rid):
        parser = reqparse.RequestParser()
        parser.add_argument('scan_status', type=int, location='form')
        args = parser.parse_args()

        r = models.Run.get(models.Run.rid == rid)
        if 'scan_status' in args:
            r.status = args['scan_status']

        r.save()
        r_json = model_to_dict(r)
        return r_json, 201

    def delete(self, rid):
        run_tasks = models.Task.select().where(models.Task.rid == rid)
        for task in run_tasks:
            tmp_tid = task.tid
            task_reports = models.Report.\
                select().\
                where((models.Report.tid == tmp_tid) & (models.Report.rid == rid))

            for report in task_reports:
                report.delete_instance()
            task.delete_instance()

        current_run = models.Run.get(models.Run.rid == rid)
        current_run_json = model_to_dict(current_run)
        current_run.delete_instance()
        return current_run_json, 204
