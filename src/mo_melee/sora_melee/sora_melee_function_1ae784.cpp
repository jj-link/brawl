#include <types.h>
#pragma force_active on

class soKineticEnergy;

class soAttributeFlag {
public:
    soAttributeFlag() : m_mask(0) { }
    soAttributeFlag(s16 bits) : m_mask(bits) { }
    ~soAttributeFlag() { }
    s16 m_mask;
};

template <typename T>
class soInstanceUnitFullProperty {
public:
    T m_element;
    s32 m_id;

    soAttributeFlag getAttribute() const;
};

template <typename T>
class soArrayVectorAbstract {
public:
    virtual void v0();
    virtual void v1();
    virtual T& at(s32 index) const;
};

template <typename T, int N>
class soInstanceManagerFullPropertyVector {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 size() const;

    u8 pad[0xC];
    soArrayVectorAbstract<soInstanceUnitFullProperty<T> > m_arrayVector;

    s32 searchIndex(s32 id) const {
        if (id <= -1)
            return -1;
        s32 sz = size();
        for (s32 i = 0; i < sz; i++)
            if (id == m_arrayVector.at(i).m_id)
                return i;
        return -1;
    }

    soAttributeFlag getAttribute(long id) const;
};

template <typename T, int N>
soAttributeFlag soInstanceManagerFullPropertyVector<T, N>::getAttribute(long id) const {
    s32 idx = searchIndex(id);
    if (idx < 0)
        return soAttributeFlag();
    return m_arrayVector.at(idx).getAttribute();
}

template soAttributeFlag soInstanceManagerFullPropertyVector<soKineticEnergy*, 4>::getAttribute(long) const;
