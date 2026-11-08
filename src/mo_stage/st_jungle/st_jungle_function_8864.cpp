#include <so/so_array.h>
#pragma force_active on

extern "C" void fn_51_8864(soArrayVectorAbstract<int>* self, int index) {
    int c, b, a;
    a = self->getLastIndex();
    b = self->getTopIndex();
    c = self->capacity();
    soArrayVectorCalculator::erase(*self, index, self->size(), c, b, a);
    self->setSize(self->size() - 1);
}