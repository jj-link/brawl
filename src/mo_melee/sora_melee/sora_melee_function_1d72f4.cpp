#pragma force_active on

#include <so/article/so_article.h>

typedef soLogAttackInfo Key;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void* slot1(int);
    virtual const Key& slot2(int);
    virtual int slot3();
    virtual unsigned int slot4();
};

extern "C" int fn_27_1D78CC(Key*, Object_vptr_0*, bool*, int, int);

inline int compare(long value, long needle, const Key* key) {
    const long bound = key->_0;
    if (needle == value)
        return 0;
    return bound < value ? -1 : 1;
}

inline int compare(const Key& entry, long needle, const Key* key) {
    const long value = entry._0;
    const long bound = key->_0;
    if (needle == value)
        return 0;
    return bound < value ? -1 : 1;
}

inline int search3(Key* key, Object_vptr_0* obj, int lo, int hi,
                   bool* p, bool* n) {
    int mid = lo + (hi - lo) / 2;
    const Key& entry = obj->slot2(mid);
    const long needle = key->_0;
    int c = compare(entry, needle, key);
    if (c == 0)
        return mid;
    if (lo == hi)
        return -(lo + 1);
    if (c > 0) {
        *p = false;
        return fn_27_1D78CC(key, obj, p, mid + 1, hi);
    }
    *n = false;
    return fn_27_1D78CC(key, obj, n, lo, mid);
}

inline int search3left(Key* key, Object_vptr_0* obj, int lo, int hi,
                       bool* p, bool* n) {
    int mid = lo + (hi - lo) / 2;
    const Key& entry = obj->slot2(mid);
    const long needle = key->_0;
    int c = compare(entry, needle, key);
    if (c == 0)
        return mid;
    if (lo == hi)
        return -(lo + 1);
    if (c > 0) {
        *p = false;
        return fn_27_1D78CC(key, obj, p, mid + 1, hi);
    }
    *n = false;
    return fn_27_1D78CC(key, obj, n, lo, mid);
}

inline int search2(Key* key, Object_vptr_0* obj, int hi, int lo,
                   bool* p0, bool* n0, bool* p1, bool* n1) {
    int mid = lo + (hi - lo) / 2;
    const Key& entry = obj->slot2(mid);
    const long needle = key->_0;
    int c = compare(static_cast<long>(entry._0), needle, key);
    if (c == 0)
        return mid;
    if (lo == hi)
        return -(lo + 1);
    if (c > 0)
        return search3(key, obj, mid + 1, hi, p0, n0);
    return search3left(key, obj, lo, mid, p1, n1);
}

inline int search2left(Key* key, Object_vptr_0* obj, int hi, int lo, int mid,
                       bool* p0, bool* n0, bool* p1, bool* n1) {
    const Key& entry = obj->slot2(mid);
    const long needle = key->_0;
    int c = compare(static_cast<long>(entry._0), needle, key);
    if (c == 0)
        return mid;
    if (lo == hi)
        return -(lo + 1);
    if (c > 0)
        return search3(key, obj, mid + 1, hi, p0, n0);
    return search3left(key, obj, lo, mid, p1, n1);
}

inline int search1(Key* key, Object_vptr_0* obj, int lo,
                   bool* b0, bool* b1, bool* b2, bool* b3,
                   bool* b4, bool* b5, bool* b6, bool* b7) {
    int hi = obj->slot3() - 1;
    int mid = (hi - lo) / 2 + lo;
    const Key& entry = obj->slot2(mid);
    const long needle = key->_0;
    int c = compare(entry, needle, key);
    if (c == 0)
        return mid;
    if (lo == hi)
        return -(lo + 1);
    if (c > 0)
        return search2(key, obj, hi, mid + 1, b0, b1, b2, b3);
    hi = lo + (mid - lo) / 2;
    return search2left(key, obj, mid, lo, hi, b4, b5, b6, b7);
}

extern "C" void* fn_27_1D72F4(Object_vptr_0* obj, int value) {
    if (value <= 0) {
        if (obj->slot4() == 1)
            return 0;
        int last = obj->slot3() - 1;
        return obj->slot1(last);
    }

    int b1, b0, b3, b2, b5, b4, b7, b6;
    Key key = {value, 0, 0};
    int index;
    if (obj->slot4() == 1)
        index = -1;
    else
        index = search1(&key, obj, 0,
                        (bool*)&b0, (bool*)&b1, (bool*)&b2, (bool*)&b3,
                        (bool*)&b4, (bool*)&b5, (bool*)&b6, (bool*)&b7);

    if (index < 0 || index >= obj->slot3())
        return 0;
    return obj->slot1(index);
}