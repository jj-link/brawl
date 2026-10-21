#pragma force_active on
struct WorkArray {
    virtual void f0();
    virtual int* get();
};
struct WorkHolder {
    char padding[0x38];
    WorkArray* array;
};
extern "C" int fn_27_B8468(WorkHolder* __restrict self) {
    return *self->array->get();
}
