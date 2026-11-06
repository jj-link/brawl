#include <so/so_array.h>
#pragma force_active on

struct Pair {
    u32 a, b;
    Pair& operator=(const Pair& rhs) {
        a = rhs.a;
        b = rhs.b;
        return *this;
    }
};

struct Base1 { virtual void dummy1(); };
struct Base2 { virtual void dummy2(); };

struct Nested : Base1, Base2 {
    u32 b0;
    Pair pairs[6];
};

struct Element {
    u32 a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;
    Nested nested;
    unsigned char f0, f1;
};

extern "C" void fn_62_C380(soArrayVectorAbstract<Element>* self, int index, const Element* value) {
    int pos = soArrayVectorCalculator::insert(
        *self, index, self->isFull(), self->size(),
        self->capacity(), self->getTopIndex(), self->getLastIndex());
    self->getArrayValueConst(pos) = *value;
    self->setSize(self->size() + 1);
}
