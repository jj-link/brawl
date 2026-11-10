#include <algorithm>
#include <cstring>
#pragma force_active on

struct StringCompare {
    bool operator()(const char* a, const char* b) const {
        return (unsigned int)strcmp(a, b) >> 31;
    }
};

extern int lbl_8059E11C;
extern "C" void fn_800C33E0(const char**, const char**, const char**, void*);
extern "C" void fn_800C3098(const char**, const char**, void*);

extern "C" void fn_800C3098(const char** first, const char** last, void* compare) {
    while (true) {
        long len = static_cast<long>(last - first);
        if (len <= 1) return;
        if (len <= 20) {
            StringCompare cmp;
            std::__selection_sort<StringCompare&, const char**>(first, last, cmp);
            return;
        }

        const char** m = first + (len / 4 + lbl_8059E11C % 5);
        if (++lbl_8059E11C >= 5) lbl_8059E11C = -4;
        long pivotOffset = len * 3 / 4;
        const char** i1 = first + (pivotOffset + lbl_8059E11C % 5);
        if (++lbl_8059E11C >= 5) lbl_8059E11C = -4;

        const char** j = last - 1;
        fn_800C33E0(m, i1, j, compare);
        m = first;
        i1 = j;
        while (((unsigned int)strcmp(*m, *j) >> 31)) m++;
        do {
            i1--;
            if (m == i1) break;
        } while (!(((unsigned int)strcmp(*i1, *j) >> 31)));

        if (m < i1) {
            std::swap(*m, *i1);
            m++;
            while (true) {
                while (((unsigned int)strcmp(*m, *j) >> 31)) m++;
                while (!(((unsigned int)strcmp(*--i1, *j) >> 31))) {}
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
            if (!(((unsigned int)strcmp(*first, *--i1) >> 31))) {
                while (m != last && !(((unsigned int)strcmp(*first, *m) >> 31))) m++;
                if (m < i1) std::swap(*m, *i1);
            }
            if (m < i1) {
                while (true) {
                    while (!(((unsigned int)strcmp(*first, *m) >> 31))) m++;
                    while (((unsigned int)strcmp(*first, *--i1) >> 31)) {}
                    if (m < i1) {
                        std::swap(*m, *i1);
                        m++;
                    } else break;
                }
            }
            first = m;
        } else if (m - first < last - m) {
            fn_800C3098(first, m, compare);
            first = m;
        } else {
            fn_800C3098(m, last, compare);
            last = m;
        }
    }
}
