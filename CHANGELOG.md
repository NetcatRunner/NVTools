# Changelog

All notable changes to NVTools are documented in this file.

The format follows [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and the project follows [Semantic Versioning](https://semver.org/).

## [Unreleased]

### Added

- `NVTools::String::join()`: joins strings or numbers of any range with a separator.
- `NVTools::String::joinString()`: joins a `std::vector<std::string>`, with or without a one-character delimiter.
- `NVTools::versionMajor()`, `versionMinor()`, `versionPatch()`, `versionString()` and `buildDescription()`.
- Static or shared build (`BUILD_SHARED_LIBS`), install rules and the `find_package(NVTools)` CMake package.
- CMake presets (`debug`, `release`, `shared`, `asan`, `tsan`), GoogleTest unit tests and the GitHub CI.
