from peewee import *

db = SqliteDatabase('swarmray.db')


class Task(Model):
    filename = CharField()
    tid = CharField()
    rid = CharField()
    hashtag = CharField()
    language = IntegerField()
    score = FloatField()

    class Meta:
        database = db

