include(FetchContent)
include_directories(../)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG 0320f517fd920866d918e564105d68fd4362040a
)

FetchContent_GetProperties(
        googletest
)

FetchContent_MakeAvailable(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

enable_testing()

add_executable(ft_test libft_mem_test.cpp libft_str_test.cpp libft_list_test.cpp)
target_compile_options(ft_test  PRIVATE "$<$<CONFIG:DEBUG>:-w>")
target_link_libraries(ft_test libft gtest_main)

include(GoogleTest)
gtest_discover_tests(ft_test)