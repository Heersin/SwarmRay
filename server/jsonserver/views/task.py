from flask_restful import reqparse, Resource


class TaskList(Resource):
    def post(self):
        pass

    def get(self):
        pass


class Task(Resource):
    def get(self, task_id):
        pass

    def delete(self, task_id):
        pass

