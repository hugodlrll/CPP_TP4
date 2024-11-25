/**
 * @file TU_Polygone.cpp
 * @author DELARUELLE Hugo, DEPEYRIS Julien, DARGERE Lucas, LAVAUX Bastien
 * @brief Tests unitaires de la classe Polygone
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <gtest/gtest.h>
#include "../src/polygone.hpp"

/**
 * @brief Test du constructeur de la classe Polygone
 * 
 */
TEST(Polygone, testPolygone) {
    Point2D<int> p1(1, 2);
    Point2D<int> p2(3, 4);
    Point2D<int> p3(5, 6);
    Polygone<int> poly({p1, p2, p3});
    EXPECT_EQ(poly.getSommets().size(), 3);
    EXPECT_EQ(poly.getSommets()[0].getX(), 1);
    EXPECT_EQ(poly.getSommets()[0].getY(), 2);
    EXPECT_EQ(poly.getSommets()[1].getX(), 3);
    EXPECT_EQ(poly.getSommets()[1].getY(), 4);
    EXPECT_EQ(poly.getSommets()[2].getX(), 5);
    EXPECT_EQ(poly.getSommets()[2].getY(), 6);    
}

/**
 * @brief Test de la translation du polygone
 * 
 */
TEST(Polygone, testTranslate) {
    Point2D<int> p1(1, 2);
    Point2D<int> p2(3, 4);
    Point2D<int> p3(5, 6);
    Polygone<int> poly({p1, p2, p3});
    poly.translate(2, 3);
    EXPECT_EQ(poly.getSommets()[0].getX(), 3);
    EXPECT_EQ(poly.getSommets()[0].getY(), 5);
    EXPECT_EQ(poly.getSommets()[1].getX(), 5);
    EXPECT_EQ(poly.getSommets()[1].getY(), 7);
    EXPECT_EQ(poly.getSommets()[2].getX(), 7);
    EXPECT_EQ(poly.getSommets()[2].getY(), 9);
}