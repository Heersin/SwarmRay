from plugins.plugin_config import support_plugins


def main(target_path):
    for plugin_name in support_plugins:
        plugin = support_plugins[plugin_name]()
        plugin.info()
        plugin.run(target_path)


if __name__ == '__main__':

    main("tests/clang_test1.cpp")