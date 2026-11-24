#include <algorithm>
#pragma force_active on

struct SortEntry {
    float x;
    float y;
    float z;
};

struct SortIterator {
    SortEntry* entry;

    SortEntry& operator*() const { return *entry; }

    SortIterator& operator++() {
        ++entry;
        return *this;
    }

    SortIterator operator--() {
        --entry;
        return *this;
    }

    SortIterator operator-(long offset) const {
        SortIterator result = {entry - offset};
        return result;
    }

    long operator-(const SortIterator& other) const {
        return entry - other.entry;
    }

    int operator==(const SortIterator& other) const { return entry == other.entry; }
    int operator!=(const SortIterator& other) const { return entry != other.entry; }
    int operator<(const SortIterator& other) const { return entry < other.entry; }
};

inline SortIterator operator+(SortIterator it, long offset) {
    it.entry += offset;
    return it;
}

struct IteratorOrder {
    bool less;
};

inline IteratorOrder compareIterators(const SortIterator& first, const SortIterator& last) {
    IteratorOrder order = {first < last != 0};
    return order;
}

struct CompareEntry {
    int operator()(const SortEntry& a, const SortEntry& b) const {
        return a.y < b.y;
    }
};

extern int lbl_40_data_FCA8;
extern "C" void fn_40_34F90(SortIterator, SortIterator, SortIterator, CompareEntry&);
extern "C" void fn_40_34A34(SortIterator, SortIterator, CompareEntry&);

inline int rangeEmpty(SortIterator end, const SortIterator& current) {
    return current == end;
}

extern "C" void fn_40_344D8(SortIterator first, SortIterator last, CompareEntry compare) {
            SortIterator final;
    while (true) {
        long len = last - first;
        if (len <= 1)
            return;

        if (len <= 20) {
            SortIterator current;
            SortIterator end;
            end = last;
            current = first;
            if (rangeEmpty(end, current))
                return;

            final = end;
            for (--final; current != final; ++current) {
                SortIterator smallest = std::min_element<SortIterator, CompareEntry&>(current, end, compare);
                if (smallest != current)
                    std::swap(*smallest, *current);
            }
            return;
        }

        SortIterator m = first + (len / 4 + lbl_40_data_FCA8 % 5);
        if (++lbl_40_data_FCA8 >= 5)
            lbl_40_data_FCA8 = -4;

        long pivotOffset = len * 3 / 4;
        SortIterator i1 = first + (pivotOffset + lbl_40_data_FCA8 % 5);
        if (++lbl_40_data_FCA8 >= 5)
            lbl_40_data_FCA8 = -4;

        SortIterator j = last - 1;
        fn_40_34F90(m, i1, j, compare);

        m = first;
        i1 = j;
        while (compare(*m, *j))
            ++m;

        do {
            --i1;
            if (m == i1)
                break;
        } while (!compare(*i1, *j));

        if (m < i1) {
            std::swap(*m, *i1);
            ++m;
            while (true) {
                while (compare(*m, *j))
                    ++m;
                while (!compare(*--i1, *j)) {}
                if (compareIterators(m, i1).less) {
                    std::swap(*m, *i1);
                    ++m;
                } else {
                    break;
                }
            }
        }

        if (m == first) {
            std::swap(*m, *j);
            ++m;
            i1 = last;
            if (!compare(*first, *--i1)) {
                while (m != last && !compare(*first, *m))
                    ++m;
                if (m < i1)
                    std::swap(*m, *i1);
            }
            if (m < i1) {
                while (true) {
                    while (!compare(*first, *m))
                        ++m;
                    while (compare(*first, *--i1)) {}
                    if (compareIterators(m, i1).less) {
                        std::swap(*m, *i1);
                        ++m;
                    } else {
                        break;
                    }
                }
            }
            first = m;
        } else if (m - first < last - m) {
            fn_40_34A34(first, m, compare);
            first = m;
        } else {
            fn_40_34A34(m, last, compare);
            last = m;
        }
    }
}