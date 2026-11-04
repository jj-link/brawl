#include <types.h>
#pragma force_active on

struct Vec { float x, y, z; };
struct Array;
struct ArrayVTable {
    void* rtti;
    int offset;
    void (*isNull)();
    Vec* (*at)(Array*, int);
    void (*slot2)();
    void (*slot3)();
    void (*slot4)();
    void (*slot5)();
    void (*slot6)();
    void (*slot7)();
    void (*slot8)();
    void (*slot9)();
    void (*push)(Array*, const void*);
};
struct Array {
    ArrayVTable* vtable;
    void* calc;
    unsigned int flags;
    unsigned char value[4];
};
class ArrayInterface {
public:
    virtual void isNull();
    virtual Vec* at(int);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void push(const void*);
};
class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29(int, Array*, Array*);
};
extern ArrayVTable lbl_27_data_1B58;
extern ArrayVTable lbl_27_data_1980;
extern const float lbl_27_rodata_344;

extern "C" Vec fn_27_16778(soNullable* self, int index, int value) {
    Array ints;
    struct VecArray : Array { unsigned char extra[8]; } vecs;
    ints.vtable = &lbl_27_data_1B58;
    ints.calc = (char*)&lbl_27_data_1B58 + 0x48;
    ints.flags &= 0x01FFFFFF;
    vecs.vtable = &lbl_27_data_1980;
    vecs.calc = (char*)&lbl_27_data_1980 + 0x48;
    vecs.flags &= 0x01FFFFFF;
    reinterpret_cast<ArrayInterface*>(&ints)->push(&value);
    Vec zero;
    zero.x = lbl_27_rodata_344;
    zero.y = lbl_27_rodata_344;
    zero.z = lbl_27_rodata_344;
    reinterpret_cast<ArrayInterface*>(&vecs)->push(&zero);
    self->slot29(index, &ints, &vecs);
    return *reinterpret_cast<ArrayInterface*>(&vecs)->at(0);
}
