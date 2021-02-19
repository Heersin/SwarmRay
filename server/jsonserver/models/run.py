from peewee import *

db = SqliteDatabase('swarmray.db')


class Run(Model):
    scan_name = CharField()
    rid = CharField()
    hashtag = CharField()
    target_path = CharField()
    count = IntegerField()
    scan_date = CharField()
    score = FloatField()
    scan_status = IntegerField()

    class Meta:
        database = db

