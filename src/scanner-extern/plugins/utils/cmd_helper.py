import subprocess


class CmdHelper:
    def __init__(self, command):
        self.cmd_output = []
        self.cmd_err = []

        self._proc = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        print("[+]exec> " + subprocess.list2cmdline(self._proc.args))

        self._cmd_output = self._proc.stdout.readlines()
        self._cmd_err = self._proc.stderr.readlines()

        for line in self._cmd_output:
            self.cmd_output.append(str(line, encoding='utf-8'))

        for line in self._cmd_err:
            self.cmd_err.append(str(line, encoding='utf-8'))

    def get_output(self):
        return self.cmd_output

    def get_err(self):
        return self.cmd_err

