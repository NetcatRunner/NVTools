<div align="center">
  <h1>🛠️ NVTools</h1>
  <p><em>The versatile C++23 utility library</em></p>

  <p>
    Reusable, well-tested building blocks for any modern C++ project.
    <br />
    <a href="https://github.com/NetcatRunner/NVTools/tree/main/examples"><strong>Examples</strong></a>
    ·
    <a href="CHANGELOG.md"><strong>Changelog</strong></a>
    ·
    <a href="https://github.com/NetcatRunner/NVTools/issues">Report a Bug</a>
  </p>

  <img src="https://img.shields.io/badge/C%2B%2B-23-00599C?style=flat-square&logo=c%2B%2B&logoColor=white" alt="C++23">
  <img src="https://img.shields.io/badge/CMake-3.28%2B-064F8C?style=flat-square&logo=cmake&logoColor=white" alt="CMake 3.28+">
  <img src="https://img.shields.io/badge/Platform-Linux-lightgrey?style=flat-square" alt="Supported Platforms">
  <br>
  <img src="https://img.shields.io/github/v/release/NetcatRunner/NVTools?style=flat-square&logo=github&color=blue" alt="Latest Release">
  <img src="https://img.shields.io/github/license/NetcatRunner/NVTools?style=flat-square" alt="License: MIT">
  <a href="https://github.com/NetcatRunner/NVTools/actions/workflows/ci.yml"><img src="https://github.com/NetcatRunner/NVTools/actions/workflows/ci.yml/badge.svg" alt="Build Status"></a>
</div>

---

## 📖 Table of Contents

  - [About the Project](#-about)
  - [Available Modules](#-modules)
  - [Getting Started](#-getting-started)
  - [Usage Example](#-usage-example)
  - [Community & Contributing](#-community--contributing)
  - [License](#-license)

---

## 🚀 About

**NVTools** is a versatile C++23 utility library.

Born from the need to stop rewriting the same boilerplate code across different applications, NVTools provides a reusable set of C++ utilities designed to make everyday development faster, safer, and more efficient. Every module is unit-tested, built without warnings and checked with sanitizers, and the library works as a static or a shared library.

## 🧰 Modules

Include `<NVTools/NVTools.hpp>` for everything, or only the header of a module, such as `<NVTools/String/String.hpp>`.

| Module | Namespace | Highlights |
|---|---|---|
| 🔤 String | `NVTools::String` | Join strings and numbers with a separator |
| 🏷️ Version | `NVTools` | Version of the headers and of the binary, build description |
| 🧩 More | | *Coming soon* |

## 🛠 Getting Started

**Requirements:** a C++23 compiler (GCC 14+; Clang and MSVC are not tested yet) and CMake 3.28+.

Add NVTools to your `CMakeLists.txt` with FetchContent:

```cmake
include(FetchContent)
FetchContent_Declare(NVTools
    GIT_REPOSITORY https://github.com/NetcatRunner/NVTools.git
    GIT_TAG main   # or a release tag, such as v0.1.0
)
FetchContent_MakeAvailable(NVTools)

target_link_libraries(my_app PRIVATE NVTools::NVTools)
```

Or install it and use `find_package`:

```bash
cmake --workflow --preset release
cmake --install build/release --prefix /path/to/install
```

```cmake
find_package(NVTools CONFIG REQUIRED)   # with -DCMAKE_PREFIX_PATH=/path/to/install
target_link_libraries(my_app PRIVATE NVTools::NVTools)
```

| CMake option | Default | Description |
|---|---|---|
| `BUILD_SHARED_LIBS` | `OFF` | Build NVTools as a shared library |
| `NVTOOLS_BUILD_TESTS` | `ON` for the main project | Build the unit tests (requires GoogleTest, through vcpkg) |
| `NVTOOLS_BUILD_EXAMPLES` | `ON` for the main project | Build the examples |
| `NVTOOLS_INSTALL` | `ON` for the main project | Generate the install rules and the CMake package |
| `NVTOOLS_WERROR` | `OFF` (`ON` in the presets) | Treat warnings as errors |

## 💻 Usage Example

Here is a quick glimpse of how easy it is to use NVTools in your main application:

```cpp
#include <NVTools/NVTools.hpp>

#include <print>
#include <string>
#include <vector>

int main() {
    std::println("{}", NVTools::buildDescription());   // NVTools 0.0.0 (GCC, Release)

    const std::vector<std::string> words = {"alpha", "beta", "gamma"};
    std::println("{}", NVTools::String::join(words, ", "));        // alpha, beta, gamma
    std::println("{}", NVTools::String::join({1, 2, 3}, " + "));   // 1 + 2 + 3
}
```

More in the [examples](https://github.com/NetcatRunner/NVTools/tree/main/examples).

## 🤝 Community & Contributing

**NVTools is a community-driven library.** Whether you want to fix a bug, add a function, add a module or fix a typo, your help is welcome: see [CONTRIBUTING.md](CONTRIBUTING.md) to get started, and [CHANGELOG.md](CHANGELOG.md) for what changed in each release. To report a security problem, follow [SECURITY.md](SECURITY.md).

## 📄 License

Distributed under the MIT License. See [LICENSE](https://github.com/NetcatRunner/NVTools/blob/main/LICENSE) for more information.
