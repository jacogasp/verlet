//
// Created by Jacopo Gasparetto on 29/09/21.
//

#include "Verlet/QuadTree.h"
#include <vector>
#include <random>
#include <memory>
#include <iostream>

using DataPoint = QuadTreeDataPoint<int> ;

void makeRandomPoint(DataPoint &point) {
    static auto generator = std::default_random_engine();
    static auto distribution = std::uniform_real_distribution<float>(0, 100);
    static int i = 0;

    point.x = distribution(generator);
    point.y = distribution(generator);
    point.data = new int (i++);
}

void printPoint(DataPoint &p) {
    std::cout << "x: " << p.x << ", y: " << p.y << ", data: " << *p.data << ", data_addr: " << &p.data << std::endl;
}

int main() {
    BoundingBox bb{ 0.f, 0.f, 100, 100 };
    QuadTree<int> qt{ bb };
    const int n = 100;

    std::vector<DataPoint> points;
    points.resize(n);

    auto generator = []() {
        DataPoint p;
        makeRandomPoint(p);
        return p;
    };

    std::generate_n(points.begin(), n, generator);

    for (auto &p : points) {
        printPoint(p);
        qt.insert(p);
    }

    std::cout << std::endl;

    // Test the entire screen
    std::vector<DataPoint*> result;

    qt.query(bb, result);

    for (auto &p : result)
        printPoint(*p);

    std::cout << "\nFound " << result.size() << " points\n";

//    for (auto &p : result)
//        delete p->data;


    result.clear();

    // Test only a portion of the screen
    bb = BoundingBox{0, 0, 10, 10};
    qt.query(bb, result);

    for (auto &p : result)
        printPoint(*p);

    std::cout << "\nFound " << result.size() << " points\n";

    for (auto &p : result)
        delete p->data;



    return 0;
}