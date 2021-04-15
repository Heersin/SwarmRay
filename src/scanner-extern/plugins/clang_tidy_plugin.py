from .BasePlugin import BasePlugin
from .utils import cmd_helper
import re
from time.datetime import datetime

class ClangTidyOfficial(BasePlugin):
    name = "clang tidy official plugin"
    description = "call clang to check Cpp Codes"
    version = "0.0.1"
    plugin_file = "clang_tidy_plugin.py"

    def run(self, extra_args):
        target_file = extra_args['target_path']
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

        # dirty and quick

        for result in grp_output:
            tokens = result.split(':')

            lv = tokens[3]
            desc_and_policy = tokens[4].split('[')
            desc = desc_and_policy[0]
            #policy = desc_and_policy[1]

            print('FILENAME: {}'.format(tokens[0]))
            print('\tPOSITION: line {} col {}'.format(tokens[1], tokens[2]))
            print('\tDESCRIPTION: {}'.format(desc))
            #print('\tPOLICY: {}'.format(policy))
            print('\tLEVEL: {}'.format(lv))


        return

    def info(self):
        print("[PLUGIN]--{}-{}".format(self.name, self.version))
        print("\tDescription {}".format(self.description))
        return

