#include <so/so_array.h>
#pragma force_active on

struct Item {
    int a;
    int b;
    int c;
    int d;
    unsigned char e;
};

extern "C" void fn_27_E6DA8(soArrayVectorAbstract<Item>* self, const Item* value) {
    *(&self->getArrayValueConst(soArrayVectorCalculator::unshift(
        *self, self->isFull(), self->capacity(), self->getTopIndex(), self->getLastIndex()))) = *value;
    self->setSize(self->size() + 1);
}