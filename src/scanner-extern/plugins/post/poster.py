from . import config
import requests

def send_run(run_data):
    requests.post(
        config.NEW_RUN_API,
        run_data
    )

def send_task(run_id, task_data):
    requests.post(
        config.NEW_TASK_API,
        task_data
    )
