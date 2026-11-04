#include <so/so_array.h>
#pragma force_active on

extern "C" void fn_72_8D50(soArrayVectorAbstract<int>* self, int index) {
    soArrayVectorCalculator::erase(*self, index, self->size(), self->capacity(), self->getTopIndex(), self->getLastIndex());
    self->setSize(self->size() - 1);
}
