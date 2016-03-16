project(local_tsp)

add_executable(local_tsp loader.cpp city.cpp graphe.cpp main.cpp)

install(TARGETS local_tsp RUNTIME DESTINATION bin)
