project(local_tsp)

add_executable(local_tsp city.cpp graphe.cpp loader.cpp main.cpp)

install(TARGETS local_tsp RUNTIME DESTINATION bin)
