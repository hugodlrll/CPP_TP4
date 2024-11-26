/**
 * @file TU_ZN.cpp
 * @author DELARUELLE Hugo, DEPEYRIS Julien, DARGERE Lucas, LAVAUX Bastien
 * @brief Tests unitaires de la classe ZN
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <gtest/gtest.h>
#include "../src/ZN.hpp"

/**
 * @brief Test du constructeur de la classe ZN
 * 
 */
TEST(ZN, testZN) {
    Point2D<int> p1(1, 1);
    Point2D<int> p2(1, 2);
    Point2D<int> p3(2, 2);
    Point2D<int> p4(2, 1);
    Polygone<int> poly({p1, p2, p3, p4});
    ZN z(1, "proprietaire", poly, -1);
    EXPECT_EQ(z.getNumero(), 1);
    EXPECT_EQ(z.getProprietaire(), "proprietaire");
    EXPECT_EQ(z.getSurface(), 1);
    EXPECT_EQ(z.getType(), "ZN");
    EXPECT_EQ(z.getPConstruct(), -1);
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
 * @brief TEst des setters de la classe ZN
 * 
 */
TEST(ZN, testZNSetter) {
    Point2D<int> p1(1, 1);
    Point2D<int> p2(1, 2);
    Point2D<int> p3(2, 2);
    Point2D<int> p4(2, 1);
    Polygone<int> poly({p1, p2, p3, p4});
    ZN z(1, "proprietaire", poly, 0);
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
    EXPECT_EQ(z.getSurface(), 1);
    EXPECT_EQ(z.getType(), "ZN");
    EXPECT_EQ(z.getPConstruct(), -1);
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
 * @brief Test du calcul de la surface d'une parcelle en forme de triangle
 * 
 */
TEST(ZN, testCalculSurfaceTriangle) {
    Point2D<int> p1(0, 0);
    Point2D<int> p2(0, 4);
    Point2D<int> p3(4, 0);
    Polygone<int> poly({p1, p2, p3});
    ZN z(1, "proprietaire", poly, -1);
    EXPECT_EQ(z.calculSurface(poly), 8);
}
