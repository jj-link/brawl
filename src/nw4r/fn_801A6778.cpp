#include <algorithm>
#pragma force_active on

struct SortEntry {
    float value;
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
};

typedef int (*Compare)(const SortEntry&, const SortEntry&);

extern int lbl_8059E900;
extern "C" void fn_801A72F0(SortEntry*, SortEntry*, SortEntry*, Compare&);
extern "C" void fn_801A6D34(SortEntry*, SortEntry*, Compare&);

extern "C" void fn_801A6778(SortEntry* first, SortEntry* last, Compare compare) {
    while (true) {
        long len = static_cast<long>(last - first);
        if (len <= 1) return;
        if (len <= 20) {
            std::__selection_sort<Compare&, SortEntry*>(first, last, compare);
            return;
        }

        SortEntry* m = first + (len / 4 + lbl_8059E900 % 5);
        if (++lbl_8059E900 >= 5) lbl_8059E900 = -4;
        long pivotOffset = len * 3 / 4;
        SortEntry* i1 = first + (pivotOffset + lbl_8059E900 % 5);
        if (++lbl_8059E900 >= 5) lbl_8059E900 = -4;

        SortEntry* j = last - 1;
        fn_801A72F0(m, i1, j, compare);
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
            fn_801A6D34(first, m, compare);
            first = m;
        } else {
            fn_801A6D34(m, last, compare);
            last = m;
        }
    }
}
