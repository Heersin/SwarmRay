from .BasePlugin import BasePlugin


class ClangTidyOfficial(BasePlugin):
    name = "clang tidy official plugin"
    description = "call clang to check Cpp Codes"
    version = "0.0.1"
    plugin_file = "clang_tidy_plugin.py"

    def run(self, target_file):
        print("CLANG TIDY SCAN TARGET {}".format(target_file))
        return

    def info(self):
        print("[PLUGIN]--{}-{}".format(self.name, self.version))
        print("\tDescription {}".format(self.description))
        return

