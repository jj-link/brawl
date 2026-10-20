#pragma force_active on
struct soKineticEnergy;

typedef unsigned int u32;
typedef int s32;
typedef unsigned short u16;
typedef short s16;

template <typename T>
class soInstanceUnitFullProperty {
public:
    soInstanceUnitFullProperty();

    u32 m_0;
    s32 m_4;
    u16 m_8;
    s16 m_a;
    u32 m_c[4];
};

template <typename T>
soInstanceUnitFullProperty<T>::soInstanceUnitFullProperty() {
    m_4 = -1;
    m_8 = 0;
    m_a = -1;
}

template class soInstanceUnitFullProperty<soKineticEnergy*>;
