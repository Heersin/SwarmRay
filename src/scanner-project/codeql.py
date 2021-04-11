import sys
from config import lang_configs
import os

def create_database(path, lang, db_name, compile_cmd):
    db_path = './databases/' + db_name
    cmd = 'codeql database create {} --language={} --source-root {} --command '.format(db_name, lang, path) + compile_cmd
    # TODO enable db creation
    return db_path

def run_proj_scanner(scan_config, db_path, output_format='csv'):
    count = 0
    db_name = db_path.split('/')[-1]

    for suite in scan_config:
        cmd = 'codeql database analyze {} {} --output=./{}_result_{} --format={}'.format(db_path, suite, db_name, count, output_format)
        count += 1
        os.system(cmd)
    
    # concat these files
    output_name = '../output/' + db_name + '_result.' + output_format
    for i in range(count):
        result_slice = "{}_result_{}".format(db_name, i)
        cmd = "cat {} >> {}".format(result_slice, output_name)
        os.system(cmd)

def scan(path, lang, compile_cmd):
    db_name = path.split('/')[-1] + '_qldb'

    try:
        db_path = create_database(path, lang, db_name, compile_cmd)
    except:
        print("[*]Failed to create db, check arguments !")
        exit(-1)

    current_config = lang_configs[lang]
    run_proj_scanner(current_config, db_path)

    print("[*]Finish Project Scan")

if __name__ == '__main__' :
    scan('jq', 'cpp', 'make')