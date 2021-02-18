from peewee import *

db = SqliteDatabase('swarmray.db')


class Run(Model):
    scan_name = CharField()
    rid = CharField()
    hashtag = CharField()
    target_path = CharField()
    count = IntegerField()
    scan_date = DateField()
    score = FloatField()

    class Meta:
        database = db

