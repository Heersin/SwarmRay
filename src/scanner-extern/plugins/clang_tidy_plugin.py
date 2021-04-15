from .BasePlugin import BasePlugin
from .utils import cmd_helper
import re
from datetime import datetime
from .post import poster

class ClangTidyOfficial(BasePlugin):
    name = "clang tidy official plugin"
    description = "call clang to check Cpp Codes"
    version = "0.0.1"
    plugin_file = "clang_tidy_plugin.py"

    def run(self, extra_args):
        target_file = self.target
        project_name = extra_args['proj_name']
        rid = extra_args['rid']
        scan_date = datetime.now().strftime("%d/%m/%Y %H:%M:%S")

        print("CLANG TIDY SCAN TARGET {}".format(target_file))

        clang_tidy_string = "clang-tidy"
        clang_tidy_checks = "-checks=*"
        #clang_tidy_other_args = "-header-filter=.*"

        no_compile_flag = '--'
        cmd = cmd_helper.CmdHelper([clang_tidy_string, target_file, clang_tidy_checks, no_compile_flag])

        raw_output = cmd.get_output()
        raw_output = ''.join(raw_output)

        pattern_str = "\n(.*)]\n"
        pattern = re.compile(pattern_str)
        grp_output = re.findall(pattern, raw_output)

        # register a run then send it to json server
        run_data = {
            'rid' : rid,
            'target_path' : target_file,
            'scan_name' : project_name,
            'scan_date' : scan_date
        }
        poster.send_run(run_data)

        # dirty and quick
        count = 0
        for result in grp_output:
            count += 1
            paras = result.split(': ')

            # first part
            tokens = paras[0].split(':')
            filename = tokens[0]
            position = tokens[1] + ':' + tokens[2]

            # second part
            lv = paras[1]

            # third part
            desc_and_policy = paras[2].split('[')
            desc = desc_and_policy[0]
            policy = desc_and_policy[1]

            task_data = {
                'filename' : filename,
                'tid' : count,
                'rid' : rid,
                'language' : 'cpp',
                'level' : lv,
                'message' : desc,
                'pos' : position,
                'rule' : policy
            }
            poster.send_task(task_data)

            print('FILENAME: {}'.format(filename))
            print('\tPOSITION: {}'.format(position))
            print('\tMESSAGE: {}'.format(desc))
            print('\tPOLICY: {}'.format(policy))
            print('\tLEVEL: {}'.format(lv))


        return

    def info(self):
        print("[PLUGIN]--{}-{}".format(self.name, self.version))
        print("\tDescription {}".format(self.description))
        return

