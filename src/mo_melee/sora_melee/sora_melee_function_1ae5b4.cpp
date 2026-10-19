#include <types.h>
#pragma force_active on

class soKineticEnergy;

template <class T, u32 C>
class soInstanceManagerFullPropertyVector {
public:
    virtual void vf0();
    virtual T& at(s32 id);
    virtual void set(const T& elm, s32 id);
};

template <>
void soInstanceManagerFullPropertyVector<soKineticEnergy*, 4>::set(soKineticEnergy* const& elm, s32 id) {
    soKineticEnergy*& ref = at(id);
    ref = elm;
}
