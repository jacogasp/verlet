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
    point.data = i++;
}

void printPoint(DataPoint &p) {
    std::cout << "x: " << p.x << ", y: " << p.y << ", data: " << p.data << ", data_addr: " << &p.data << std::endl;
}

int main() {
    BoundingBox<int> bb{ 0.f, 0.f, 100, 100 };
    QuadTree<int> qt{ bb };
    const int n = 100;

    for (int i = 0; i < n; ++i) {
        DataPoint p;
        makeRandomPoint(p);
        printPoint(p);
        qt.insert(p);
    }
    std::cout << std::endl;

    std::vector<DataPoint> result;

    qt.query(bb, result);

    for (auto &p : result)
        printPoint(p);


    std::cout << "\nFound " << result.size() << " points\n";

    return 0;
}