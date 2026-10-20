#include <types.h>
#pragma force_active on

class soKineticEnergy;

class soAttributeFlag {
public:
    s16 m_mask;
    soAttributeFlag() : m_mask(0) { }
    soAttributeFlag(s16 bits) : m_mask(bits) { }
    ~soAttributeFlag() { }
};

template <typename T>
class soInstanceUnit {
public:
    T m_element;
    s32 m_id;
    soInstanceUnit() : m_element(), m_id(-1) { }
    soInstanceUnit(T& elm, s32 id) : m_element(elm), m_id(id) { }
};

template <typename T>
class soInstanceUnitFullProperty : public soInstanceUnit<T> {
public:
    soAttributeFlag m_attribute;
    s16 m_10;

    soInstanceUnitFullProperty() : m_attribute(), m_10(-1) { }
    soInstanceUnitFullProperty(T& elm, s32 id, soAttributeFlag attr, s16 p4) :
        soInstanceUnit<T>(elm, id), m_attribute(attr), m_10(p4) { }
    ~soInstanceUnitFullProperty() { }

    soAttributeFlag getAttribute() const;
};

template <typename T>
soAttributeFlag soInstanceUnitFullProperty<T>::getAttribute() const {
    return m_attribute;
}

template class soInstanceUnitFullProperty<soKineticEnergy*>;
