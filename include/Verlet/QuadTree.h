//
// Created by Jacopo Gasparetto on 24/09/21.
//

#ifndef VERLET_QUADTREE_H
#define VERLET_QUADTREE_H

#include <vector>
#include <memory>
#include <iostream>

struct QuadTreeDataPoint {
    float x;
    float y;
//    void *data;
    std::shared_ptr<void>data;
};

struct BoundingBox {
    float x0;
    float y0;
    float x1;
    float y1;

    bool contains(const QuadTreeDataPoint &data) const;

    bool intersects(const BoundingBox &box) const;
};

class QuadTreeNode {
protected:
    static constexpr int QT_NODE_CAPACITY = 4;

    std::unique_ptr<QuadTreeNode> northWest;
    std::unique_ptr<QuadTreeNode> northEast;
    std::unique_ptr<QuadTreeNode> southWest;
    std::unique_ptr<QuadTreeNode> southEast;

    BoundingBox m_boundingBox;
    int m_count = 0;
    std::vector<std::shared_ptr<QuadTreeDataPoint>> m_points;

public:

    explicit QuadTreeNode(const BoundingBox &boundingBox);

    void subdivide();

    bool insert(const std::shared_ptr<QuadTreeDataPoint>& data);

    void query(const BoundingBox &box, std::vector<std::shared_ptr<QuadTreeDataPoint>> &result);
};

class QuadTree : public QuadTreeNode {
public:
    explicit QuadTree(const BoundingBox &boundingBox) : QuadTreeNode(boundingBox) {};
};


#endif //VERLET_QUADTREE_H
