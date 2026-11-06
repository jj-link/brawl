#pragma force_active on

#include <so/so_array.h>

struct Item {
    int a;
    int b;
};

extern "C" void fn_57_CCA4(soArrayVectorAbstract<Item>* self, s32 index, const Item* src) {
    s32 pos = soArrayVectorCalculator::insert(
        *self, index, self->isFull(), self->size(), self->capacity(),
        self->getTopIndex(), self->getLastIndex());
    self->getArrayValueConst(pos) = *src;
    self->setSize(self->size() + 1);
}
