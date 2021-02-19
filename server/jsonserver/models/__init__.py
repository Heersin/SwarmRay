from peewee import SqliteDatabase
import os
from .task import Task
from .run import Run
from .report import Report
import sys
sys.path.append('..')
import config

db = SqliteDatabase(config.DATABASE_NAME)


# TODO More Robust
def db_init():
    if os.path.exists(config.DATABASE_NAME):
        print('[*]Use original Sqlite db')
        return
    try:
        db.connect()
        db.create_tables([Task, Run, Report])
        print("[*]Init Database ...")
        db.close()
    except Exception:
        # TODO More Exception
        print("[x]Init Database Failed")


def db_connect():
    db.connect()


def db_close():
    db.close()