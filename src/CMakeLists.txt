cmake_minimum_required(VERSION 3.15)
project(tn_base_src)


install(DIRECTORY include/ DESTINATION include/tn/tn_base)


#
# tn_base
#

add_library(tn_base STATIC 
        "tn_base.cpp"
        )

add_library(tn::tn_base ALIAS tn_base)

target_include_directories(tn_base
		PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
        PUBLIC "$<INSTALL_INTERFACE:include/tn/tn_base>"
        )

target_link_libraries(tn_base
        PUBLIC Boost::filesystem
        PUBLIC spdlog::spdlog
        )

target_compile_features(tn_base
        PUBLIC cxx_std_20
        )

set_target_properties(tn_base PROPERTIES
        PREFIX ""
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS NO
        POSITION_INDEPENDENT_CODE ON
        )

install(TARGETS tn_base EXPORT "tn-base-config"
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
        