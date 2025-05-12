#ifndef POINT_SET_LIST_H
#define POINT_SET_LIST_H

#include "point_set.h"
#include <vector>

class PointSetList {
    private:
        PointSet* head;
        PointSet* tail;
    
    public:
        PointSetList();
        ~PointSetList();

        void AddPoint(const Point& p);
        std::vector<PointSet*> FindNbrSets(const Point& p) const;
        size_t Size() const;

        PointSet* GetHead() const { return head; }
        PointSet* GetTail() const { return tail; }
};

#endif