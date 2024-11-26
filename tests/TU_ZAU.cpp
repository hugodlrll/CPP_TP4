/**
 * @file TU_ZAU.cpp
 * @author DELARUELLE Hugo DEPEYRIS Julien DARGERE Lucas LAVAUX Bastien
 * @brief Tests unitaires de la classe ZAU
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <gtest/gtest.h>
#include "../src/ZAU.hpp"

/**
 * @brief Test du constructeur de la classe ZAU
 * 
 */
TEST(ZAU, testZAU) {
    Point2D<int> p1(1, 1);
    Point2D<int> p2(1, 2);
    Point2D<int> p3(2, 2);
    Point2D<int> p4(2, 1);
    Polygone<int> poly({p1, p2, p3, p4});
    ZAU z(1, "proprietaire", poly, 2);
    EXPECT_EQ(z.getNumero(), 1);
    EXPECT_EQ(z.getProprietaire(), "proprietaire");
    EXPECT_EQ(z.getSurface(), 1);
    EXPECT_EQ(z.getType(), "ZAU");
    EXPECT_EQ(z.getPConstruct(), 2);
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
 * @brief Test des setters de la classe ZAU
 * 
 */
TEST(ZAU, testZAUSetter) {
    Point2D<int> p1(1, 1);
    Point2D<int> p2(1, 2);
    Point2D<int> p3(2, 2);
    Point2D<int> p4(2, 1);
    Polygone<int> poly({p1, p2, p3, p4});
    ZAU z(1, "proprietaire", poly, 2);
    z.setNumero(2);
    z.setProprietaire("nouveau proprietaire");
    Point2D<int> p5(3, 3);
    Point2D<int> p6(3, 4);
    Point2D<int> p7(4, 4);
    Point2D<int> p8(4, 3);
    Polygone<int> poly2({p5, p6, p7, p8});
    z.setForme(poly2);
    EXPECT_EQ(z.getNumero(), 2);
    EXPECT_EQ(z.getProprietaire(), "nouveau proprietaire");
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
 * @brief Test de la méthode surfaceConstructible de la classe ZAU
 * 
 */
TEST(ZAU, testSurfaceConstructible) {
    Point2D<int> p1(1, 1);
    Point2D<int> p2(1, 2);
    Point2D<int> p3(2, 2);
    Point2D<int> p4(2, 1);
    Polygone<int> poly({p1, p2, p3, p4});
    ZAU z(1, "proprietaire", poly, 40);
    EXPECT_EQ(z.surfaceConstructible(), 0);
    z.setPConstruct(100);
    EXPECT_EQ(z.surfaceConstructible(), 1);
}



