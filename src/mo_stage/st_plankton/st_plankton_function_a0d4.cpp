#include <so/so_array.h>
#pragma force_active on

struct Item {
    int a;
    int b;
};

extern "C" void fn_74_A0D4(soArrayVectorAbstract<Item>* self, int index, const Item* src) {
    int pos = soArrayVectorCalculator::insert(*self, index, self->isFull(), self->size(), self->capacity(), self->getTopIndex(), self->getLastIndex());
    self->getArrayValueConst(pos) = *src;
    self->setSize(self->size() + 1);
}
