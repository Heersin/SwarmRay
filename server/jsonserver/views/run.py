from flask_restful import reqparse, Resource
from playhouse.shortcuts import model_to_dict
import json
import sys
sys.path.append('..')
import models


class RunList(Resource):
    def get(self):
        result = []
        for r in models.Run().select():
            result.append(model_to_dict(r))
        result_json = json.dumps(result)
        return result_json, 200

    def post(self):
        parser = reqparse.RequestParser()
        parser.add_argument('rid', location='form', required=True)
        parser.add_argument('hashtag', location='form', required=True)
        parser.add_argument('target_path', location='form', required=True)
        parser.add_argument('count', type=int, location='form', required=True)
        parser.add_argument('scan_name', location='form', required=True)
        parser.add_argument('scan_date', location='form', required=True)
        parser.add_argument('score', type=float, location='form', required=True)
        parser.add_argument('scan_status', type=int, location='form', required=True)
        args = parser.parse_args()

        new_run = models.Run().create(
            scan_name=args['scan_name'],
            rid=args['rid'],
            hashtag=args['hashtag'],
            target_path=args['target_path'],
            count=args['count'],
            scan_date=args['scan_date'],
            score=args['score'],
            scan_status=args['scan_status']
        )

        new_run.save()
        new_run_json = json.dumps(model_to_dict(new_run))
        return new_run_json, 201


class Run(Resource):
    def get(self, run_id):
        r = models.Run().get(models.Run.rid == run_id)
        r_json = json.dumps(model_to_dict(r))
        return r_json, 200

    def patch(self, run_id):
        parser = reqparse.RequestParser()
        parser.add_argument('scan_status', type=int, location='form')
        parser.add_argument('score', type=float, location='form')
        args = parser.parse_args()

        r = models.Run().get(models.Run.rid == run_id)
        if 'scan_status' in args:
            r.status = args['scan_status']
        if 'score' in args:
            r.score = args['score']

        r.save()
        r_json = json.dumps(model_to_dict(r))
        return r_json, 201

    def delete(self, run_id):
        run_tasks = models.Task.select().where(models.Task.rid == run_id)
        for task in run_tasks:
            tmp_tid = task.tid
            task_reports = models.Report.\
                select().\
                where((models.Report.tid == tmp_tid) & (models.Report.rid == run_id))

            for report in task_reports:
                report.delete_instance()
            task.delete_instance()

        current_run = models.Run.get(models.Run.rid == run_id)
        current_run_json = json.dumps(model_to_dict(current_run))
        current_run.delete_instance()
        return current_run_json, 204
