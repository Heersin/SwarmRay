from peewee import *
from datetime import datetime
from playhouse.shortcuts import model_to_dict
import json

db = SqliteDatabase('test.db')

class Run(Model):
    scan_name = CharField()
    rid = CharField()
    hashtag = CharField()
    target_path = CharField()
    count = IntegerField()
    scan_date = CharField()
    score = FloatField()

    class Meta:
        database = db


if __name__ == '__main__':
    db.connect()
    db.create_tables([Run])

    now=datetime.now()

    first_run = Run(
            scan_name='test',
            scan_date=now.strftime('%Y%m%d-%H:%M:%S'),
            rid='2020010101',
            hashtag='123456abcdefg',
            target_path='test/',
            count=10,
            score=2.0)

    first_run.save()
    result = []

    for r in Run.select():
        print(model_to_dict(r))
        result.append(model_to_dict(r))

    print(json.dumps(result))

    db.close()
