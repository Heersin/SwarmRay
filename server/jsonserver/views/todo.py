from jsondb import abort_if_todo_doesnt_exist, fetch_db_todos, remove_db_todo, insert_db_todo, update_db_todo
from flask_restful import reqparse, Resource

class Todo(Resource):
    def get(self, todo_id):
        abort_if_todo_doesnt_exist(todo_id)
        todos = fetch_db_todos()
        return todos[todo_id]

    def delete(self, todo_id):
        abort_if_todo_doesnt_exist(todo_id)
        remove_db_todo(todo_id)
        return '', 204

    def put(self, todo_id):
        parser = reqparse.RequestParser()
        parser.add_argument('task')
        args = parser.parse_args()

        task = {'task': args['task']}
        update_db_todo(todo_id, task)
        return task, 201


class TodoList(Resource):
    def get(self):
        TODOS = fetch_db_todos()
        return TODOS

    def post(self):
        parser = reqparse.RequestParser()
        parser.add_argument('task')
        args = parser.parse_args()
        TODOS = fetch_db_todos()

        todo_id = int(max(TODOS.keys()).lstrip('todo')) + 1
        todo_id = 'todo%i' % todo_id
        task = {'task': args['task']}

        update_db_todo(todo_id, task)

        TODOS = fetch_db_todos()
        return TODOS[todo_id], 201