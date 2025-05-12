#include "point_set.h"
#include <iostream>

PointSet::PointSet() : prev(nullptr), next(nullptr) {}

PointSet::~PointSet() {
    if (prev) prev->next = next;
    if (next) next->prev = prev;
}

void PointSet::AddPoint(const Point& p) {
    points.insert(p);
}

bool PointSet::Contains(const Point& p) const {
    return points.find(p) != points.end();
}

bool PointSet::IsNbr(const Point& p) const {
    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            if (Contains(Point(p.x + dx, p.y + dy))) {
                return true;
            }
        }
    }
    return false;
}

void PointSet::MergeWith(PointSet* other) {
    // какой бегин и энд в UNORDERED сете ??
    points.insert(other->GetPoints().begin(), other->GetPoints().end());

    delete other;
}