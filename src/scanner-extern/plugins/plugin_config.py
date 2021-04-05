from .clang_tidy_plugin import ClangTidyOfficial

support_plugins = {
    "clang_tidy_official": ClangTidyOfficial
}

enabled_plugins = [
    ClangTidyOfficial,
]