#pragma force_active on
struct Data;
struct Iface;

struct Array {
    virtual void unused0();
    virtual Data* at(int index);
};

struct Object {
    char pad0[0x30];
    Iface* iface;
    char pad34[0x24];
    Array* array;
};

extern "C" int fn_27_428A0(Data*, Iface*, int);
extern "C" int fn_27_428E0(const Data*);

extern "C" int fn_27_44EB0(Object* self, int value, int index) {
    int first = fn_27_428A0(self->array->at(index), self->iface, value);
    int second = fn_27_428E0(self->array->at(index));
    return first > second ? first : second;
}
