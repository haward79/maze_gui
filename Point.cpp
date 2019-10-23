#include "Point.h"

namespace NutnDS_Point
{
    // Constructor.
    Point::Point() : i(0), j(0)
    {
        // Empty.
    }

    Point::Point(int i, int j) : i(i), j(j)
    {
        // Empty.
    }

    // Constructor.
    PointSet::PointSet()
    {
        for(int i=0; i<kMaxPoint; ++i)
            set[i] = new Point();

        size = 0;
    }

    // Destructor.
    PointSet::~PointSet()
    {
        for(int i=0; i<kMaxPoint; ++i)
            delete set[i];
    }

    // Accesor.
    const int PointSet::getPointI(int index) const
    {
        if(index>=0 && index<size)
            return set[index]->getI();
        else
            return 0;
    }

    const int PointSet::getPointJ(int index) const
    {
        if(index>=0 && index<size)
            return set[index]->getJ();
        else
            return 0;
    }

    const bool PointSet::setPointI(int index, int value)
    {
        if(index>=0 && index<size)
        {
            set[index]->setI(value);
            return true;
        }
        else
            return false;
    }
    
    const bool PointSet::setPointJ(int index, int value)
    {
        if(index>=0 && index<size)
        {
            set[index]->setJ(value);
            return true;
        }
        else
            return false;
    }

    // Method.
    Point* PointSet::pop()
    {
        if(size > 0)
        {
            --size;
            return new Point(set[size]->getI(), set[size]->getJ());
        }
        else
            return new Point();
    }

    bool PointSet::push(int i, int j)
    {
        if(size < kMaxPoint)
        {
            set[size]->setI(i);
            set[size]->setJ(j);
            ++size;

            return true;
        }
        else
            return false;
    }
}

