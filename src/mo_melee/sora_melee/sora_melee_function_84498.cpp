#include <types.h>
#pragma force_active on

class soLinkEventObserver;

template <typename T>
class soInstanceUnitFullProperty {
public:
    virtual ~soInstanceUnitFullProperty();
};

template <typename T>
soInstanceUnitFullProperty<T>::~soInstanceUnitFullProperty() { }

template class soInstanceUnitFullProperty<soLinkEventObserver*>;