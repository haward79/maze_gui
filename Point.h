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
                const int getI() const { return i; }
                const int getJ() const { return j; }

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

                // Destructor.
                ~PointSet();

                // Accesor.
                const int getPointI(int) const;
                const int getPointJ(int) const;
                const int getSize() const { return size; }

                // Mutator.
                const bool setPointI(int, int);
                const bool setPointJ(int, int);

                // Method.
                Point* pop();
                bool push(int, int);

            private:
                // Variable.
                Point* set[kMaxPoint];
                int size;
        };
    }

#endif

