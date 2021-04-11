cpp_config = [
    'rules/cpp/codeql-suites/cpp-security-and-quality.qls',
    'rules/cpp/codeql-suites/cpp-security-extended.qls',
]

js_config = []

lang_configs = {
    'cpp' : cpp_config,
    'javascript' : js_config
}