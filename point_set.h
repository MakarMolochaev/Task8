#ifndef POINT_SET_H
#define POINT_SET_H

#include "point.h"
#include <unordered_set>

class PointSet {
    private:
        std::unordered_set<Point> points;
        PointSet* prev;
        PointSet* next;
    
    public:
        PointSet();
        ~PointSet();

        void AddPoint(const Point& p);
        bool Contains(const Point& p) const;
        bool IsNbr(const Point& p) const;

        PointSet* GetPrev() const { return prev; }
        PointSet* GetNext() const { return next; }
        void SetPrev(PointSet* p) { prev = p; }
        void SetNext(PointSet* p) { next = p; }

        const std::unordered_set<Point>& GetPoints() const { return points; }

        void MergeWith(PointSet* other);
};

#endif