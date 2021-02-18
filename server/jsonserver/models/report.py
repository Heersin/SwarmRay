from peewee import *

db = SqliteDatabase('swarmray.db')


class Report(Model):
    tid = CharField()
    policy = CharField()
    description = CharField()
    score = FloatField()
    vuln_type = CharField()
    scanner = CharField()
    position = CharField()

    class Meta:
        database = db