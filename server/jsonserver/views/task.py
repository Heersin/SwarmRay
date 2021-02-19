from flask_restful import reqparse, Resource
from playhouse.shortcuts import model_to_dict
import json
import sys
sys.path.append('..')
import models


class TaskList(Resource):
    def post(self):
        # TODO Move Parser into config
        # or other place
        parser = reqparse.RequestParser()
        parser.add_argument('filename', location='form', required=True)
        parser.add_argument('tid', location='form', required=True)
        parser.add_argument('rid', location='form', required=True)
        parser.add_argument('hashtag', location='form', required=True)
        parser.add_argument('language', type=int, location='form', required=True)
        parser.add_argument('score', type=float, location='form', required=True)
        args = parser.parse_args()

        task = models.Task.create(
            filename=args['filename'],
            tid=args['tid'],
            rid=args['rid'],
            hashtag=args['hashtag'],
            language=args['language'],
            score=args['score']
        )

        task.save()
        task_json = json.dumps(model_to_dict(task))
        return task_json, 201

    def get(self):
        result = []
        for task in models.Task.select():
            result.append(model_to_dict(task))

        result_json = json.dumps(result)
        return result_json, 200


class Task(Resource):
    def get(self, run_id):
        parser = reqparse.RequestParser()
        parser.add_argument('tid', location='args')
        args = parser.parse_args()

        if 'tid' in args:
            tid = args['tid']
        else:
            # list task by given run_id
            result = []
            tasks = models.Task().select().where(models.Task.rid == run_id)
            for t in tasks:
                result.append(model_to_dict(t))
            result_json = json.dumps(result)
            return result_json, 200

        task = models.Task().select().where(
            (models.Task.tid == tid) & (models.Task.rid == run_id)
        ).get()

        task_json = json.dumps(model_to_dict(task))
        return task_json, 200

    def delete(self, run_id):
        parser = reqparse.RequestParser()
        parser.add_argument('tid', location='args')
        args = parser.parse_args()

        tasks = []

        if 'tid' in args:
            tid = args['tid']
            tmp_task = models.Task().select().where(
                (models.Task.tid == tid) & (models.Task.rid == run_id)
            ).get()
            tasks.append(tmp_task)
        else:
            run_tasks = models.Task().select().where(models.Task.rid == run_id)
            for t in run_tasks:
                tasks.append(t)

        # delete related report
        for t in tasks:
            tmp_tid = t.tid
            tmp_rid = run_id

            tmp_reports = models.Report().select().where(
                (models.Report.tid == tmp_tid) & (models.Report.rid == tmp_rid)
            )

            # delete reports
            for r in tmp_reports:
                r.delete_instance()

            # delete task
            t.delete_instance()

        return '', 204
