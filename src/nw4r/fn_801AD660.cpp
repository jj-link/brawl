#include <algorithm>
#pragma force_active on

typedef int (*Compare)(unsigned int, unsigned int);
extern int lbl_8059E914;
extern "C" void fn_801AD9E0(unsigned int*, unsigned int*, unsigned int*, Compare&);

extern "C" void fn_801AD660(unsigned int* first, unsigned int* last, Compare& compare) {
    while (true) {
        long len = static_cast<long>(last - first);
        if (len <= 1) return;
        if (len <= 20) {
            std::__selection_sort<Compare&, unsigned int*>(first, last, compare);
            return;
        }
        unsigned int* m = first + (len / 4 + lbl_8059E914 % 5);
        if (++lbl_8059E914 >= 5) lbl_8059E914 = -4;
        long pivotOffset = len * 3 / 4;
        unsigned int* i1 = first + (pivotOffset + lbl_8059E914 % 5);
        if (++lbl_8059E914 >= 5) lbl_8059E914 = -4;

        unsigned int* j = last - 1;
        fn_801AD9E0(m, i1, j, compare);
        m = first;
        i1 = j;
        while (compare(*m, *j)) m++;
        do {
            i1--;
            if (m == i1) break;
        } while (!compare(*i1, *j));

        if (m < i1) {
            std::swap(*m, *i1);
            m++;
            while (true) {
                while (compare(*m, *j)) m++;
                while (!compare(*--i1, *j)) {}
                if (m < i1) {
                    std::swap(*m, *i1);
                    m++;
                } else break;
            }
        }

        if (m == first) {
            std::swap(*m, *j);
            m++;
            i1 = last;
            if (!compare(*first, *--i1)) {
                while (m != last && !compare(*first, *m)) m++;
                if (m < i1) std::swap(*m, *i1);
            }
            if (m < i1) {
                while (true) {
                    while (!compare(*first, *m)) m++;
                    while (compare(*first, *--i1)) {}
                    if (m < i1) {
                        std::swap(*m, *i1);
                        m++;
                    } else break;
                }
            }
            first = m;
        } else if (m - first < last - m) {
            fn_801AD660(first, m, compare);
            first = m;
        } else {
            fn_801AD660(m, last, compare);
            last = m;
        }
    }
}