# Ajouter les fichiers source et d'en-tête
set(SOURCES
    ../src/main.cpp
    ../src/parcelle.cpp
    ../src/ZN.cpp
    ../src/ZA.cpp
    ../src/ZU.cpp
    ../src/ZAU.cpp
    ../src/carte.cpp
)

set(HEADERS
    ../src/point2D.hpp
    ../src/polygone.hpp
    ../src/parcelle.hpp
    ../src/constructible.hpp
    ../src/ZN.hpp
    ../src/ZA.hpp
    ../src/ZU.hpp
    ../src/ZAU.hpp
    ../src/carte.hpp
)

# Créer l'exécutable
add_executable(main ${SOURCES} ${HEADERS})