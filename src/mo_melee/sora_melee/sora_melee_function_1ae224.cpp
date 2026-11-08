#include <types.h>
#pragma force_active on

class soKineticEnergy;

struct soInstanceAttribute {
    s16 m_mask;
};

template <class T>
class soInstanceUnitFullProperty {
public:
    T m_element;
    s32 m_id;
    s16 m_attribute;
    s16 m_10;
    soInstanceUnitFullProperty(T const&, s32, s16 const&, s16);
};

template <class T, u32 C>
class soArrayVector {
public:
    virtual void v0();
    virtual void v1();
    virtual soInstanceUnitFullProperty<T>* at(s32) const;
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void insert(s32, soInstanceUnitFullProperty<T>*);
    virtual void v12();
    virtual void v13();
    virtual unsigned int isFull() const;
    char pad[0x38];
};

template <class T, u32 C>
class soInstanceManagerFullPropertyVector {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 size() const;
    virtual void v5();
    virtual unsigned int isContain(s32) const;
    char pad[0xC];
    soArrayVector<T, C> m_av;
    u8 m_unk1;

    s32 getFreeId() const;
    s32 find(s32 p4) const {
        s32 sz = size();
        for (s32 i = 0; i < sz; i++) {
            s16 r0 = m_av.at(i)->m_10;
            if (r0 <= -1)
                return i;
            if (r0 > p4)
                return i;
        }
        return sz;
    }
    s32 add(T const&, s32, soInstanceAttribute const&, s16);
};

template <class T, u32 C>
s32 soInstanceManagerFullPropertyVector<T, C>::add(T const& elm, s32 id, soInstanceAttribute const& attr, s16 p4) {
    if (m_av.isFull() == true)
        return -1;
    if ((!m_unk1 || id > -1) && isContain(id) == true)
        return -1;
    if (!m_unk1 && id <= -1) {
        id = getFreeId();
        if (id <= -1)
            return -1;
    }
    s32 idx = (p4 <= -1) ? size() : find(p4);
    if (idx < 0)
        return -1;
    s16 sp8 = attr.m_mask;
    soInstanceUnitFullProperty<T> spC(elm, id, sp8, p4);
    m_av.insert(idx, &spC);
    return id;
}

template s32 soInstanceManagerFullPropertyVector<soKineticEnergy*, 4>::add(soKineticEnergy* const&, s32, soInstanceAttribute const&, s16);
