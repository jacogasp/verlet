//
// Created by Jacopo Gasparetto on 29/09/21.
//

#include "Verlet/QuadTree.h"
#include <vector>
#include <random>
#include <memory>
#include <iostream>

void makeRandomPoint(std::shared_ptr<QuadTreeDataPoint> &point) {
    static auto generator = std::default_random_engine();
    static auto distribution = std::uniform_real_distribution<float>(0, 100);
    static int i = 0;

    point->x = distribution(generator);
    point->y = distribution(generator);
    point->data = std::make_shared<char>('A' + i++);
}

void printPoint(QuadTreeDataPoint &p) {
    auto c = std::static_pointer_cast<char>(p.data);
    std::cout << "x: " << p.x << ", y: " << p.y << ", data: " << *c << ", data_addr: " << p.data.get() << std::endl;
}

int main() {
    BoundingBox bb{ 0.f, 0.f, 100, 100 };
    QuadTree qt{ bb };
    const int n = 10;

    for (int i = 0; i < n; ++i) {
        auto p = std::make_shared<QuadTreeDataPoint>();
        makeRandomPoint(p);
        printPoint(*p);
        qt.insert(p);
    }

    std::vector<std::shared_ptr<QuadTreeDataPoint>> result;

    qt.query(bb, result);

    for (auto &p : result)
        printPoint(*p);

    return 0;
}