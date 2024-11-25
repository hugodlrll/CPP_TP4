/**
 * @file TU_Point2D.cpp
 * @author DELARUELLE Hugo, DEPEYRIS Julien, DARGERE Lucas, LAVAUX Bastien
 * @brief Tests unitaires de la classe Point2D
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <gtest/gtest.h>
#include "../src/point2D.hpp"

/**
 * @brief Test du constructeur de la classe Point2D
 * 
 */
TEST(Point2D, testPoint2D) {
    Point2D<int> p1(1, 2);
    Point2D<int> p2(p1);
    EXPECT_EQ(p1.getX(), p2.getX());
    EXPECT_EQ(p1.getY(), p2.getY());
    p1.setX(3);
    p1.setY(4);
    EXPECT_EQ(p1.getX(), 3);
    EXPECT_EQ(p1.getY(), 4);
}

/**
 * @brief Test de la translation du point
 * 
 */
TEST(Point2D, testTranslate) {
    Point2D<int> p1(1, 2);
    p1.translate(2, 3);
    EXPECT_EQ(p1.getX(), 3);
    EXPECT_EQ(p1.getY(), 5);
}

