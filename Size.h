#ifndef Size_h

    namespace NutnDS_Size
    {
        class Size
        {
            private:
                // Variable.
                int height;
                int width;

            public:
                // Constructor.
                Size();
                Size(int, int);

                // Accessor.
                int getHeight() const { return height; }
                int getWidth() const { return width; }

                // Mutator.
                bool setHeight(int);
                bool setWidth(int);
        };
    }

#endif

