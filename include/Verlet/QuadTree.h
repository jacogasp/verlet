//
// Created by Jacopo Gasparetto on 24/09/21.
//

#ifndef VERLET_QUADTREE_H
#define VERLET_QUADTREE_H

#include <vector>
#include <memory>
#include <iostream>

template<typename T>
struct QuadTreeDataPoint {
    float x;
    float y;
    T data;
};

template<typename T>
struct BoundingBox {
    float x0;
    float y0;
    float x1;
    float y1;

    bool contains(const QuadTreeDataPoint<T> &data) const {
        return x0 <= data.x && data.x <= x1 && y0 <= data.y && data.y <= y1;
    }

    bool intersects(const BoundingBox &box) const {
        return x0 <= box.x1 && x1 >= box.x0 && y0 <= box.y1 && y1 >= box.y0;
    }
};

template<typename T>
class QuadTreeNode {
protected:
    static constexpr int QT_NODE_CAPACITY = 4;

    std::unique_ptr<QuadTreeNode> northWest;
    std::unique_ptr<QuadTreeNode> northEast;
    std::unique_ptr<QuadTreeNode> southWest;
    std::unique_ptr<QuadTreeNode> southEast;

    BoundingBox<T> m_boundingBox;
    int m_count = 0;
    std::vector<QuadTreeDataPoint<T>> m_points;

public:

    explicit QuadTreeNode(const BoundingBox<T> &boundingBox) :
            m_boundingBox(boundingBox) {}

    void subdivide() {

        float xMid = (m_boundingBox.x0 + m_boundingBox.x1) * .5f;
        float yMid = (m_boundingBox.y0 + m_boundingBox.y1) * .5f;
        float width = (m_boundingBox.x1 - m_boundingBox.x0) * .5f;
        float height = (m_boundingBox.y1 - m_boundingBox.y0) * .5f;

        BoundingBox<T> nw{ m_boundingBox.x0, m_boundingBox.y0, m_boundingBox.x0 + width, m_boundingBox.y0 + height };
        BoundingBox<T> ne{ xMid, m_boundingBox.y0, xMid + width, m_boundingBox.y0 + height };
        BoundingBox<T> sw{ m_boundingBox.x0, yMid, m_boundingBox.x0 + width, yMid + height };
        BoundingBox<T> se{ xMid, yMid, xMid + width, yMid + height };

        northEast = std::make_unique<QuadTreeNode>(ne);
        northWest = std::make_unique<QuadTreeNode>(nw);
        southEast = std::make_unique<QuadTreeNode>(se);
        southWest = std::make_unique<QuadTreeNode>(sw);
    }

    bool insert(const QuadTreeDataPoint<T>& data) {

        // Ignore objects that do not belong to this node
        if (!m_boundingBox.contains(data))
            return false;

        // If there is space in this quad tree and if it doesn't have subdivisions, add the object here
        if (m_count < QT_NODE_CAPACITY && northWest == nullptr) {
            m_points.push_back(data);
            m_count++;
            return true;
        }

        // Otherwise, subdivide and then add the point to whichever node will accept it
        if (northWest == nullptr)
            subdivide();

        // We have to add the points contained int this quad array to the new quads if we only want the last node
        // to hold the point

        if (northWest->insert(data)) return true;
        if (northEast->insert(data)) return true;
        if (southWest->insert(data)) return true;
        if (southEast->insert(data)) return true;

        // Otherwise, the point cannot be inserted for some unknown reason (this should never happen)
        return false;
    }

    void query(const BoundingBox<T> &box, std::vector<QuadTreeDataPoint<T>> &result) {

        // Automatically abort if the range does not intersect this quad
        if (!m_boundingBox.intersects(box))
            return;

        // Check objects at this quad level
        for (auto &el: m_points)
            if (m_boundingBox.contains(el))
                result.push_back(el);

        // If there are no children, terminate here
        if (northWest == nullptr)
            return;

        // Otherwise, add the points from the children
        northWest->query(box, result);
        northEast->query(box, result);
        southWest->query(box, result);
        southEast->query(box, result);
    }
};

template <typename T>
class QuadTree : public QuadTreeNode<T> {
public:
   using QuadTreeNode<T>::QuadTreeNode;
};


#endif //VERLET_QUADTREE_H
