find_package(Boost COMPONENTS "filesystem" REQUIRED)
find_package(spdlog CONFIG REQUIRED)

_find_package(${ARGS})
