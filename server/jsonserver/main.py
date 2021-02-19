from flask import Flask
from flask_restful import reqparse, Api, Resource
from views import task
from views import run
import models

app = Flask(__name__)
api = Api(app)


##
## Actually setup the Api resource routing here
##
api.add_resource(task.Task, '/v1/tasks/<rid>')
api.add_resource(task.TaskList, '/v1/tasks')
api.add_resource(run.RunList, '/v1/runs')
api.add_resource(run.Run, '/v1/runs/<rid>')


if __name__ == '__main__':
    models.db_init()
    models.db_connect()
    app.run(debug=True)
    models.db_close()