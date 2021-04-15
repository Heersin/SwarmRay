from plugins.plugin_config import support_plugins
from plugins.plugin_config import enabled_plugins

def main(target_path, extra_args):
    for plugin_class in enabled_plugins:
        plugin = plugin_class()
        plugin.target = target_path
        plugin.run(extra_args)

# TODO : Format it to tablet output style
def list_plugins():
    for plugin_name in support_plugins:
        plugin_class = support_plugins[plugin_name]
        plugin = plugin_class()
        plugin.info()

if __name__ == '__main__':

    extra_args = {
        'proj_name' : 'plugin_test',
        'rid' : '2'
    }
    main("tests/clang_test1.cpp", extra_args)
    list_plugins()