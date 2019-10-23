#include "Size.h"

namespace NutnDS_Size
{
    // Constructor.
    Size::Size() : height(0), width(0)
    {
        // Empty.
    }

    Size::Size(int height, int width) : height(0), width(0)
    {
        setHeight(height);
        setWidth(width);
    }

    // Mutator.
    bool Size::setHeight(int height)
    {
        if(height >= 0)
        {
            this->height = height;
            return true;
        }
        else
            return false;
    }

    bool Size::setWidth(int width)
    {
        if(width >= 0)
        {
            this->width = width;
            return true;
        }
        else
            return false;
    }
}

