# One executable per example, linked like a real client of the library.
function(nvtools_add_example name)
    add_executable(${name} ${ARGN})
    target_link_libraries(${name} PRIVATE NVTools::NVTools NVTools::Flags)
endfunction()

add_subdirectory(String)
