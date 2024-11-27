/**
 * @file TU_ZA.cpp
 * @author DELARUELLE Hugo DEPEYRIS Julien DARGERE Lucas LAVAUX Bastien
 * @brief Tests unitaires de la classe ZA
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <gtest/gtest.h>
#include "../src/ZA.hpp"

/**
 * @brief Test du constructeur de la classe ZA
 * 
 */
TEST(ZA, testZA) {
    Point2D<int> p1(1, 1);
    Point2D<int> p2(1, 2);
    Point2D<int> p3(2, 2);
    Point2D<int> p4(2, 1);
    Polygone<int> poly({p1, p2, p3, p4});
    ZA z(1, "proprietaire", poly, "culture");
    EXPECT_EQ(z.getNumero(), 1);
    EXPECT_EQ(z.getProprietaire(), "proprietaire");
    EXPECT_EQ(z.getSurface(), 1);
    EXPECT_EQ(z.getType(), "ZA");
    EXPECT_EQ(z.getCulture(), "culture");
    EXPECT_EQ(z.getForme().getSommets()[0].getX(), 1);
    EXPECT_EQ(z.getForme().getSommets()[0].getY(), 1);
    EXPECT_EQ(z.getForme().getSommets()[1].getX(), 1);
    EXPECT_EQ(z.getForme().getSommets()[1].getY(), 2);
    EXPECT_EQ(z.getForme().getSommets()[2].getX(), 2);
    EXPECT_EQ(z.getForme().getSommets()[2].getY(), 2);
    EXPECT_EQ(z.getForme().getSommets()[3].getX(), 2);
    EXPECT_EQ(z.getForme().getSommets()[3].getY(), 1);
}

/**
 * @brief Test des setters de la classe ZA
 * 
 */
TEST(ZA, testZASetter) {
    Point2D<int> p1(1, 1);
    Point2D<int> p2(1, 2);
    Point2D<int> p3(2, 2);
    Point2D<int> p4(2, 1);
    Polygone<int> poly({p1, p2, p3, p4});
    ZA z(1, "proprietaire", poly, "culture");
    z.setNumero(2);
    z.setProprietaire("nouveau proprietaire");
    z.setTypeCulture("nouvelle culture");
    Point2D<int> p5(3, 3);
    Point2D<int> p6(3, 4);
    Point2D<int> p7(4, 4);
    Point2D<int> p8(4, 3);
    Polygone<int> poly2({p5, p6, p7, p8});
    z.setForme(poly2);
    EXPECT_EQ(z.getNumero(), 2);
    EXPECT_EQ(z.getProprietaire(), "nouveau proprietaire");
    EXPECT_EQ(z.getCulture(), "nouvelle culture");
    EXPECT_EQ(z.getForme().getSommets()[0].getX(), 3);
    EXPECT_EQ(z.getForme().getSommets()[0].getY(), 3);
    EXPECT_EQ(z.getForme().getSommets()[1].getX(), 3);
    EXPECT_EQ(z.getForme().getSommets()[1].getY(), 4);
    EXPECT_EQ(z.getForme().getSommets()[2].getX(), 4);
    EXPECT_EQ(z.getForme().getSommets()[2].getY(), 4);
    EXPECT_EQ(z.getForme().getSommets()[3].getX(), 4);
    EXPECT_EQ(z.getForme().getSommets()[3].getY(), 3);
}

/**
 * @brief Test de la méthode surfaceConstructible de la classe ZA
 * 
 */
TEST(ZA, testSurfaceConstructible) {
    Point2D<int> p1(100, 100);
    Point2D<int> p2(100, 200);
    Point2D<int> p3(200, 200);
    Point2D<int> p4(200, 100);
    Polygone<int> poly({p1, p2, p3, p4});
    ZA z(1, "proprietaire", poly, "culture");
    EXPECT_EQ(z.surfaceConstructible(), 200);
    Point2D<int> p5(10, 10);
    Point2D<int> p6(10, 20);
    Point2D<int> p7(20, 20);
    Point2D<int> p8(20, 10);
    Polygone<int> poly2({p5, p6, p7, p8});
    ZA z2(1, "proprietaire", poly2, "culture");
    EXPECT_EQ(z2.surfaceConstructible(), 10);
}