# Ajouter Google Test
add_subdirectory(../googletest googletest-build)

# Activer les tests
enable_testing()

# Créer l'exécutable de tests
add_executable(TU_Point2D TU_Point2D.cpp)

# Lier Google Test et le projet principal
target_link_libraries(TU_Point2D gtest gtest_main)
