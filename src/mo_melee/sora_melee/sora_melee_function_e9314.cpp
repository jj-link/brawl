#include <types.h>
#include <so/so_array_vector_calculator.h>
#pragma force_active on

struct Item {
    s32 a;
    s32 b;
    f32 c;
    f32 d;
    s32 e;
    s32 f;
    s32 g;
    s32 h;
    s32 i;
    s32 j;
    u8 k;
    u8 l;
    u8 m;
};

class ItemArray {
public:
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual s32 size() const = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual s32 capacity() const = 0;
    virtual bool isFull() const = 0;
    virtual void slot15() = 0;
    virtual void slot16() = 0;
    virtual void slot17() = 0;
    virtual void slot18() = 0;
    virtual void slot19() = 0;
    virtual void slot20() = 0;
    virtual void slot21() = 0;
    virtual void slot22() = 0;
    virtual void slot23() = 0;
    virtual void slot24() = 0;
    virtual void slot25() = 0;
    virtual Item& getArrayValueConst(s32) = 0;
    virtual s32 getTopIndex() const = 0;
    virtual s32 getLastIndex() const = 0;
    virtual void setSize(s32) = 0;
};

extern "C" void fn_27_E9314(ItemArray* self, s32 index, const Item* newElement) {
    s32 lastIndex = soArrayVectorCalculator::insert(*(soArrayVectorCalcInterface*)((char*)self + 4), index, self->isFull(), self->size(), self->capacity(), self->getTopIndex(), self->getLastIndex());
    Item& element = self->getArrayValueConst(lastIndex);
    element = *newElement;
    self->setSize(self->size() + 1);
}
