# Contributing

Thanks for helping to improve NVTools! Bug reports, ideas and pull requests are all welcome.

## Report a bug or suggest a feature

Open an [issue](https://github.com/NetcatRunner/NVTools/issues) from one of the templates: it asks for the steps to reproduce the problem, your compiler and your operating system. A security problem goes through [SECURITY.md](SECURITY.md) instead.

## Build and test

You need a C++23 compiler (GCC 14+), CMake 3.28+, Ninja and [vcpkg](https://vcpkg.io), with `VCPKG_ROOT` set. vcpkg installs GoogleTest for the tests.

```bash
cmake --workflow --preset debug   # configure, build and test
```

| Preset | What for |
|---|---|
| `debug` | Daily work: develop, step through, test |
| `release` | What ships: optimized, link-time optimization |
| `shared` | The shared library: a public function without `NVTOOLS_API` fails the link |
| `asan` | AddressSanitizer and UndefinedBehaviorSanitizer |
| `tsan` | ThreadSanitizer (Linux and macOS) |

The CI runs `debug`, `release`, `shared` and `asan` on every push and pull request. In VS Code, pick a preset with **CMake: Select Configure Preset**.

Tests use [GoogleTest](https://google.github.io/googletest/), one `<Name>Tests.cpp` file per header, listed in the `CMakeLists.txt` of its folder:

```cpp
#include <NVTools/String/Join.hpp>

#include <gtest/gtest.h>

TEST(JoinTests, JoinsWithSeparator)
{
    EXPECT_EQ(NVTools::String::join({"a", "b"}, "-"), "a-b");
}
```

## Project layout

| Path | Contents |
|---|---|
| `include/NVTools/` | Public headers, one folder per module |
| `src/` | Implementation, one folder per module |
| `tests/Unit/` | Unit tests, one folder per module |
| `examples/` | Small programs, one folder per module |
| `cmake/` | CMake modules: options, flags, install, generated version header |

A new module `Foo` gets the same folder `Foo/` in `include/NVTools/`, `src/`, `tests/Unit/` and `examples/`, each with its `CMakeLists.txt`, and its header `Foo.hpp` is included by `NVTools.hpp`.

## Code style

- C++23 without warnings: the presets build with `-Wall -Wextra -Wpedantic -Wconversion -Werror`, and the code passes [`.clang-tidy`](.clang-tidy).
- Format with [`.clang-format`](.clang-format) before committing: `clang-format -i <files>`.
- Folders, files and types in `PascalCase`, functions and variables in `camelCase`, constants start with `k` (`kMaxSize`), private members start with `_`, macros are `NVTOOLS_UPPER_CASE`.
- Include public headers with angle brackets: `#include <NVTools/String/Join.hpp>`.
- Mark every non-inline public function with `NVTOOLS_API`, and its result with `[[nodiscard]]` when ignoring it is a bug.
- Report expected failures with `std::optional`, `std::expected` or `bool` instead of exceptions, and use `assert` for programming errors.
- Prefer simple, readable code over clever optimizations.
- Document public functions and classes with a short `///` comment, like the existing headers.

## Pull requests

1. Open or pick an issue, then create a branch from `main`: `git switch -c feat/string-split`.
2. Write focused commits that follow [Conventional Commits](https://www.conventionalcommits.org): `feat(string): add split()`, `fix(string): ...`, `build: ...`, `ci: ...`, `docs: ...`, `test: ...`, `refactor: ...`.
3. Check that the build and the tests pass, and note your change at the top of [CHANGELOG.md](CHANGELOG.md), under the `Unreleased` heading.
4. Open a pull request that explains what changes and why, and links its issue (`Closes #12`). Pull requests are squash-merged: their title becomes the commit on `main`.

Releases follow [Semantic Versioning](https://semver.org/): a breaking change bumps the major version, and before `1.0.0` the minor version.
