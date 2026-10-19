#pragma force_active on
class soKineticEnergy;

template <class T>
class soInstanceUnitFullProperty {
public:
    ~soInstanceUnitFullProperty();
};

template <>
soInstanceUnitFullProperty<soKineticEnergy*>::~soInstanceUnitFullProperty() { }
