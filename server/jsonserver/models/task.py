from peewee import *

db = SqliteDatabase('swarmray.db')


class Task(Model):
    filename = CharField()
    tid = CharField()
    rid = CharField()
    language = CharField()

    level=CharField()
    message=CharField()
    pos=CharField()
    rule=CharField()

    class Meta:
        database = db

