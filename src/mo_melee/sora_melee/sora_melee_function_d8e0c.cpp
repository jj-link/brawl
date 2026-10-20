#pragma force_active on
typedef signed int s32;
typedef signed short s16;

struct soKineticEnergy {};

template <class T>
class soInstanceUnitFullProperty {};

template <>
class soInstanceUnitFullProperty<soKineticEnergy*> {
public:
    soKineticEnergy* m_element;
    s32 m_id;
    s16 m_attribute;
    s16 m_10;

    soInstanceUnitFullProperty(soKineticEnergy* const&, long id, const s16& attribute, s16 p4);
};

soInstanceUnitFullProperty<soKineticEnergy*>::soInstanceUnitFullProperty(
    soKineticEnergy* const& element, long id, const s16& attribute, s16 p4)
{
    m_element = element;
    m_id = id;
    m_attribute = attribute;
    m_10 = p4;
}
