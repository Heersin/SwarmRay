from flask_restful import abort

TODOS = {
    'todo1': {'task': 'build an API'},
    'todo2': {'task': '?????'},
    'todo3': {'task': 'profit!'},
}

def abort_if_todo_doesnt_exist(todo_id):
    if todo_id not in TODOS:
        abort(404, message="Todo {} doesn't exist".format(todo_id))

def fetch_db_todos():
    return TODOS

def remove_db_todo(todo_id):
    del TODOS[todo_id]

def update_db_todo(todo_id, task):
    TODOS[todo_id] = task

def insert_db_todo(todo_id, task):
    TODOS[todo_id] = task