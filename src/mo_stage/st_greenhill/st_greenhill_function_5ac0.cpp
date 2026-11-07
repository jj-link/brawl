#include <so/so_array.h>

#pragma force_active on

struct Element {
    float f00, f04, f08, f0c;
    unsigned int a10, a14, a18, a1c, a20, a24, a28;
    unsigned short s2c, s2e;
    unsigned char c30, c31, c32, c33, c34, c35, c36, c37, c38, c39, c3a;
    unsigned int a3c, a40, a44, a48;
    float f4c;
    unsigned int a50, a54, a58, a5c;
    float f60, f64, f68;
    unsigned int a6c, a70, a74, a78;
    float f7c;
    unsigned int a80, a84, a88, a8c, a90;
    float f94;
    unsigned int a98;
    unsigned char c9c;
};

extern "C" void fn_72_5AC0(soArrayVectorAbstract<Element>* self, s32 index, const Element* value) {
    s32 pos = soArrayVectorCalculator::insert(*self, index, self->isFull(), self->size(), self->capacity(), self->getTopIndex(), self->getLastIndex());
    self->getArrayValueConst(pos) = *value;
    self->setSize(self->size() + 1);
}
