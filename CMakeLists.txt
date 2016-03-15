project(local_tsp)

<<<<<<< HEAD
add_executable(local_tsp loader.cpp city.cpp graphe.cpp main.cpp)
=======
add_executable(local_tsp city.cpp graphe.cpp loader.cpp main.cpp)
>>>>>>> 519644312f8c69484c5d3594f90f9c7dd5b800fc

install(TARGETS local_tsp RUNTIME DESTINATION bin)
