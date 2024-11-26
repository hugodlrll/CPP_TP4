/**
 * @file TU_ZU.cpp
 * @author DELARUELLE Hugo DEPEYRIS Julien DARGERE Lucas LAVAUX Bastien
 * @brief Tests unitaires de la classe ZU
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <gtest/gtest.h>
#include "../src/ZU.hpp"

/**
 * @brief Test du constructeur de ZU
 * 
 */
TEST(ZU, testZU) {
    Point2D<int> p1(10, 10);
    Point2D<int> p2(10, 20);
    Point2D<int> p3(20, 20);
    Point2D<int> p4(20, 10);
    Polygone<int> poly({p1, p2, p3, p4});
    ZU z(1, "prop", poly, 50, 20);
    EXPECT_EQ(z.getNumero(), 1);
    EXPECT_EQ(z.getProprietaire(), "prop");
    EXPECT_EQ(z.getType(), "ZU");
    EXPECT_EQ(z.getPContruite(), 20);
    EXPECT_EQ(z.getForme().getSommets()[0].getX(), 10);
    EXPECT_EQ(z.getForme().getSommets()[0].getY(), 10);
    EXPECT_EQ(z.getForme().getSommets()[1].getX(), 10);
    EXPECT_EQ(z.getForme().getSommets()[1].getY(), 20);
    EXPECT_EQ(z.getForme().getSommets()[2].getX(), 20);
    EXPECT_EQ(z.getForme().getSommets()[2].getY(), 20);
    EXPECT_EQ(z.getForme().getSommets()[3].getX(), 20);
    EXPECT_EQ(z.getForme().getSommets()[3].getY(), 10);
}

/**
 * @brief Test des setters de ZU
 * 
 */
TEST(ZU, testSetters) {
    Point2D<int> p1(10, 10);
    Point2D<int> p2(10, 20);
    Point2D<int> p3(20, 20);
    Point2D<int> p4(20, 10);
    Polygone<int> poly({p1, p2, p3, p4});
    ZU z(1, "prop", poly, 50, 20);
    z.setNumero(2);
    z.setProprietaire("nouveau proprietaire");
    Point2D<int> p5(30, 30);
    Point2D<int> p6(30, 40);
    Point2D<int> p7(40, 40);
    Point2D<int> p8(40, 30);
    Polygone<int> poly2({p5, p6, p7, p8});
    z.setForme(poly2);
    EXPECT_EQ(z.getNumero(), 2);
    EXPECT_EQ(z.getProprietaire(), "nouveau proprietaire");
    EXPECT_EQ(z.getPContruite(), 20);
    EXPECT_EQ(z.getForme().getSommets()[0].getX(), 30);
    EXPECT_EQ(z.getForme().getSommets()[0].getY(), 30);
    EXPECT_EQ(z.getForme().getSommets()[1].getX(), 30);
    EXPECT_EQ(z.getForme().getSommets()[1].getY(), 40);
    EXPECT_EQ(z.getForme().getSommets()[2].getX(), 40);
    EXPECT_EQ(z.getForme().getSommets()[2].getY(), 40);
    EXPECT_EQ(z.getForme().getSommets()[3].getX(), 40);
    EXPECT_EQ(z.getForme().getSommets()[3].getY(), 30);
}

/**
 * @brief Test de la méthode surfaceConstructible de ZU
 * 
 */
TEST(ZU, testSurfaceConstructible) {
    Point2D<int> p1(10, 10);
    Point2D<int> p2(10, 20);
    Point2D<int> p3(20, 20);
    Point2D<int> p4(20, 10);
    Polygone<int> poly({p1, p2, p3, p4});
    ZU z(1, "prop", poly, 50, 20);
    EXPECT_EQ(z.getSurface(), 100); 
    EXPECT_EQ(z.surfaceConstructible(), 30);
}