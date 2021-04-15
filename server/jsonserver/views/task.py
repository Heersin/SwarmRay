from flask_restful import reqparse, Resource
from .cors import CorsResource
from playhouse.shortcuts import model_to_dict
import json
import sys
sys.path.append('..')
import models


class TaskList(CorsResource):
    def post(self):
        # TODO Move Parser into config
        # or other place
        parser = reqparse.RequestParser()
        parser.add_argument('filename', location='form', required=True)
        parser.add_argument('tid', location='form', required=True)
        parser.add_argument('rid', location='form', required=True)
        parser.add_argument('language', location='form', required=True)

        parser.add_argument('level', location='form', required=True)
        parser.add_argument('message', location='form', required=True)
        parser.add_argument('pos', location='form', required=True)
        parser.add_argument('rule', location='form', required=True)
        args = parser.parse_args()

        task = models.Task.create(
            filename=args['filename'],
            tid=args['tid'],
            rid=args['rid'],
            language=args['language'],
            level=args['level'],
            message=args['message'],
            pos=args['pos'],
            rule=args['rule']
        )

        task.save()
        task_json = model_to_dict(task)
        return task_json, 201

    def get(self):
        result = []
        for task in models.Task.select():
            result.append(model_to_dict(task))

        result_json = {'data':result}
        return result_json, 200


class Task(CorsResource):
    def get(self, rid):
        parser = reqparse.RequestParser()
        parser.add_argument('tid', location='args')
        args = parser.parse_args()

        if args['tid'] is not None:
            tid = args['tid']
        else:
            # list task by given rid
            result = []
            tasks = models.Task.select().where(models.Task.rid == rid)
            for t in tasks:
                result.append(model_to_dict(t))
            result_json = {'data' : result}
            return result_json, 200

        task = models.Task.select().where(
            (models.Task.tid == tid) & (models.Task.rid == rid)
        ).get()
        print("single")

        task_json = model_to_dict(task)
        return task_json, 200

    def delete(self, rid):
        parser = reqparse.RequestParser()
        parser.add_argument('tid', location='args')
        args = parser.parse_args()

        tasks = []

        if 'tid' in args:
            tid = args['tid']
            tmp_task = models.Task.select().where(
                (models.Task.tid == tid) & (models.Task.rid == rid)
            ).get()
            tasks.append(tmp_task)
        else:
            run_tasks = models.Task.select().where(models.Task.rid == rid)
            for t in run_tasks:
                tasks.append(t)

        # delete related report
        for t in tasks:
            tmp_tid = t.tid
            tmp_rid = rid

            tmp_reports = models.Report.select().where(
                (models.Report.tid == tmp_tid) & (models.Report.rid == tmp_rid)
            )

            # delete reports
            for r in tmp_reports:
                r.delete_instance()

            # delete task
            t.delete_instance()

        return '', 204
