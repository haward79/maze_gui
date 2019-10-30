#ifndef Point_h

    #define Point_h

    namespace NutnDS_Point
    {
        class Point
        {
            public:
                // Constructor.
                Point();
                Point(int, int);

                // Accessor.
                int getI() const { return i; }
                int getJ() const { return j; }

                // Mutator.
                void setI(int i) { this->i = i; }
                void setJ(int j) { this->j = j; }

            private:
                // Variable.
                int i;
                int j;
        };

        class PointSet
        {
            // Constant.
            static const int kMaxPoint = 10000;

            public:
                // Constructor.
                PointSet();
                PointSet(const PointSet&);

                // Destructor.
                ~PointSet();

                // Accesor.
                int getPointI(int) const;
                int getPointJ(int) const;
                int getSize() const { return size; }

                // Mutator.
                bool setPointI(int, int);
                bool setPointJ(int, int);

                // Method.
                Point pop();
                bool push(int, int);

            private:
                // Variable.
                Point* set[kMaxPoint];
                int size;
        };
    }

#endif

