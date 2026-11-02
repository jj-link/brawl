#pragma force_active on
#pragma push
#pragma opt_propagation off

struct E {
    unsigned char x[8];
};

struct Data85C0 {
    E first;   // offset 0
    E second;  // offset 8
    E third;   // offset 16
};

extern "C" Data85C0 lbl_27_data_85C0;

class Array {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int size();
};

struct Object {
    unsigned char pad[0x40];
    Array* array;
};

extern "C" E* fn_27_74A04(Object* self, int index) {
    Data85C0* base = &lbl_27_data_85C0;
    if (index == -1)
        return &base->second;
    if (index < 0 || index >= self->array->size())
        return &base->third;
    E (Data85C0::*pm) = &Data85C0::first;
    return &(base->*pm);
}
#pragma pop
