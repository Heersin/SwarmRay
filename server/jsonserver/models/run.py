from peewee import *

db = SqliteDatabase('swarmray.db')


class Run(Model):
    scan_name = CharField()
    rid = CharField()
    target_path = CharField()
    scan_date = CharField()

    class Meta:
        database = db

