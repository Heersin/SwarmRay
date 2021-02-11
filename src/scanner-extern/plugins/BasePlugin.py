from abc import ABCMeta, abstractmethod


class BasePlugin(metaclass=ABCMeta):
    name = "Base Plugin"
    description = "Base Plugin Class And Should Not Be Init"
    version = "0.0.0"
    plugin_file = None

    @abstractmethod
    def run(self, target_file):
        ''' DOCs Here '''
        return

    @abstractmethod
    def info(self):
        return
