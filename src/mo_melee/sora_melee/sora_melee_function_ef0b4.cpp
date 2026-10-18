#include <types.h>
#pragma force_active on

class soLinkEventObserver;

template <class T>
class soInstanceUnitFullProperty;

// Explicit specialization: the generic template's base-class constructor
// would zero m_element, which the original does not do, so the layout is
// declared directly. Matches the original's stores: id = -1 at +0x4,
// attribute = 0 at +0x8, m_10 = -1 at +0xA.
template <>
class soInstanceUnitFullProperty<soLinkEventObserver*> {
public:
    soLinkEventObserver* m_element;
    s32 m_id;
    s16 m_attribute;
    s16 m_10;

    soInstanceUnitFullProperty();
};

soInstanceUnitFullProperty<soLinkEventObserver*>::soInstanceUnitFullProperty() : m_id(-1), m_attribute(0), m_10(-1) { }
