#pragma force_active on
typedef unsigned int u32;
typedef int s32;

class wnPikminPikmin;

struct soArrayElem {
    void* p;
    s32 a;
    s32 b;
};

template <typename T, int N>
class soArrayList {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual u32 v4();
    virtual void v5();
    virtual u32 v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();

    s32 getArrayIndex(long index) const;
    soArrayElem* at(long index);

    s32 m_count;
    s32 m_pad;
    soArrayElem m_elems[N];
};

template <typename T, int N>
soArrayElem* soArrayList<T, N>::at(long index) {
    s32 idx = getArrayIndex(index);
    if (v4() != 1) {
        if (idx >= 0) {
            v13();
        }
    }
    return &m_elems[idx];
}

template soArrayElem* soArrayList<wnPikminPikmin*, 10>::at(long);
