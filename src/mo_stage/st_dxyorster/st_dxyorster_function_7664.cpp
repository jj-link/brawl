#include <so/so_array.h>
#pragma force_active on

extern "C" void fn_76_7664(soArrayVectorAbstract<int>* self, s32 index) {
    soArrayVectorCalculator::erase(*self, index, self->size(), self->capacity(), self->getTopIndex(), self->getLastIndex());
    self->setSize(self->size() - 1);
}
