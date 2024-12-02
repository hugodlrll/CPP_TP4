# Ajouter Google Test
add_subdirectory(../googletest googletest-build)

# Activer les tests
enable_testing()

# Définir les fichiers sources et d'en-tête nécessaires
set(SOURCES
    ../src/parcelle.cpp
    ../src/ZN.cpp
    ../src/ZA.cpp
    ../src/ZU.cpp
    ../src/ZAU.cpp
    ../src/carte.cpp
    ../src/utilitaire.cpp
)

set(HEADERS
    ../src/point2D.hpp
    ../src/polygone.hpp
    ../src/parcelle.hpp
    ../src/ZN.hpp
    ../src/ZA.hpp
    ../src/ZU.hpp
    ../src/ZAU.hpp
    ../src/carte.hpp
    ../src/utilitaire.hpp
)

# Créer une bibliothèque statique avec les fichiers sources
add_library(my_library STATIC ${SOURCES} ${HEADERS})

# Définir les fichiers de test
set(TEST_SOURCES
    TU_Point2D.cpp
    TU_Polygone.cpp
    TU_ZN.cpp
    TU_ZA.cpp
    TU_ZAU.cpp
    TU_ZU.cpp
    TU_Carte.cpp
)

# Créer un exécutable pour chaque fichier de test unitaire
add_executable(TU_Point2D TU_Point2D.cpp)
add_executable(TU_Polygone TU_Polygone.cpp)
add_executable(TU_ZN TU_ZN.cpp)
add_executable(TU_ZA TU_ZA.cpp)
add_executable(TU_ZAU TU_ZAU.cpp)
add_executable(TU_ZU TU_ZU.cpp)
add_executable(TU_Carte TU_Carte.cpp)

# Lier Google Test et les fichiers sources aux exécutables de test unitaire
target_link_libraries(TU_Point2D my_library gtest gtest_main)
target_link_libraries(TU_Polygone my_library gtest gtest_main)
target_link_libraries(TU_ZN my_library gtest gtest_main)
target_link_libraries(TU_ZA my_library gtest gtest_main)
target_link_libraries(TU_ZAU my_library gtest gtest_main)
target_link_libraries(TU_ZU my_library gtest gtest_main)
target_link_libraries(TU_Carte my_library gtest gtest_main)

# Créer un exécutable global pour tous les tests unitaires
add_executable(all_tests ${TEST_SOURCES})

# Lier Google Test et les fichiers sources à l'exécutable global
target_link_libraries(all_tests my_library gtest gtest_main)

# Ajouter les tests
add_test(NAME TU_Point2D COMMAND TU_Point2D)
add_test(NAME TU_Polygone COMMAND TU_Polygone)
add_test(NAME TU_ZN COMMAND TU_ZN)
add_test(NAME TU_ZA COMMAND TU_ZA)
add_test(NAME TU_ZAU COMMAND TU_ZAU)
add_test(NAME TU_ZU COMMAND TU_ZU)
add_test(NAME all_tests COMMAND all_tests)