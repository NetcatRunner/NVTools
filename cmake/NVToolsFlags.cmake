include_guard(GLOBAL)

# ── NVTools::Flags ──────────────────────────────────────────────────────────────────────────────────────
add_library(NVToolsFlags INTERFACE)
add_library(NVTools::Flags ALIAS NVToolsFlags)

set(nvtools_stdlib_checks "$<NOT:$<CONFIG:Release>>")

target_compile_options(NVToolsFlags INTERFACE
    $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:
        -Wall -Wextra -Wpedantic
        -Wshadow -Wconversion -Wsign-conversion -Wold-style-cast
        -Wnon-virtual-dtor -Woverloaded-virtual -Wnull-dereference
        -Wdouble-promotion -Wcast-align -Wformat=2 -Wimplicit-fallthrough
        -Wextra-semi -Wunused -Wundef
        -fno-rtti
        $<$<BOOL:${NVTOOLS_WERROR}>:-Werror>>
    $<$<CXX_COMPILER_ID:GNU>:
        -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wmisleading-indentation>
    $<$<CXX_COMPILER_ID:MSVC>:
        /W4 /permissive- /utf-8 /Zc:__cplusplus /Zc:preprocessor /GR-
        $<$<BOOL:${NVTOOLS_WERROR}>:/WX>>
    $<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:GNU,Clang,AppleClang>>:-g>
    $<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:MSVC>>:/Zi>
)

set(nvtools_stdlib_checks "$<OR:$<NOT:$<CONFIG:Release>>,$<BOOL:${NVTOOLS_HARDENING}>>")

target_compile_definitions(NVToolsFlags INTERFACE
    $<${nvtools_stdlib_checks}:_GLIBCXX_ASSERTIONS>
    $<${nvtools_stdlib_checks}:_LIBCPP_HARDENING_MODE=$<IF:$<CONFIG:Release>,_LIBCPP_HARDENING_MODE_FAST,_LIBCPP_HARDENING_MODE_EXTENSIVE>>
    $<$<PLATFORM_ID:Windows>:NOMINMAX WIN32_LEAN_AND_MEAN>
)

# ── Sanitizers ─────────────────────────────
set(nvtools_sanitizers "")
if(NVTOOLS_SANITIZE_ADDRESS)
    list(APPEND nvtools_sanitizers address)
endif()
if(NVTOOLS_SANITIZE_UNDEFINED)
    list(APPEND nvtools_sanitizers undefined)
endif()
if(NVTOOLS_SANITIZE_THREAD)
    list(APPEND nvtools_sanitizers thread)
endif()

if(nvtools_sanitizers AND MSVC)
    if(NOT NVTOOLS_SANITIZE_ADDRESS)
        message(FATAL_ERROR "MSVC only provides AddressSanitizer")
    endif()
    add_compile_options(/fsanitize=address)
elseif(nvtools_sanitizers)
    list(JOIN nvtools_sanitizers "," nvtools_sanitize)
    add_compile_options(-fsanitize=${nvtools_sanitize} -fno-omit-frame-pointer -fno-sanitize-recover=all)
    add_link_options(-fsanitize=${nvtools_sanitize})
    if(NVTOOLS_SANITIZE_UNDEFINED)
        add_compile_options(-fno-sanitize=vptr)
        add_link_options(-fno-sanitize=vptr)
    endif()
    message(STATUS "NVTools: sanitizers -> ${nvtools_sanitize}")
endif()

# ── Hardening ────
if(NVTOOLS_HARDENING AND nvtools_sanitizers)
    message(STATUS "NVTools: NVTOOLS_HARDENING ignored, sanitizers are on")
elseif(NVTOOLS_HARDENING AND NOT MSVC)
    set(nvtools_optimized "$<NOT:$<CONFIG:Debug>>")
    add_compile_options(
        "$<${nvtools_optimized}:-U_FORTIFY_SOURCE;-D_FORTIFY_SOURCE=3>"
        -fstack-protector-strong -ftrivial-auto-var-init=zero)
    if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
        add_compile_options(-fstack-clash-protection)
        add_link_options(LINKER:-z,relro,-z,now,-z,noexecstack)
    endif()
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "^(x86_64|AMD64|amd64)$")
        add_compile_options(-fcf-protection=full)
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "^(aarch64|arm64|ARM64)$")
        add_compile_options(-mbranch-protection=standard)
    endif()
    message(STATUS "NVTools: hardening on")
endif()

# ── Frame pointers ──
if(NVTOOLS_FRAME_POINTERS AND NOT MSVC)
    add_compile_options(-fno-omit-frame-pointer)
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "^(x86_64|AMD64|amd64|aarch64|arm64|ARM64)$")
        add_compile_options(-mno-omit-leaf-frame-pointer)
    endif()
endif()
