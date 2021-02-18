from peewee import SqliteDatabase
import os
from .task import Task
from .run import Run
from .report import Report
from .. import config

db = SqliteDatabase(config.DATABASE_NAME)

# TODO More Robust
def db_init():
    if os.path.exists(config.DATABASE_NAME):
        return
    try:
        db.connect()
        db.create_tables([Task, Run, Report])
    except Exception:
        # TODO More Exception
        print("[x]Init Database Failed")
    finally:
        db.close()


def db_connect():
    db.connect()


def db_close():
    db.close()