#pragma force_active on
class Class_20958 {
public:
    virtual void fn_27_C76A8();
    virtual void* fn_27_C7528(int);
    virtual void fn_27_C7538();
    virtual int size__41soArrayContractibleTable_C12soStatusData_CFv();
    virtual void fn_27_C76F0();
    virtual void fn_27_C74E8();
    virtual void fn_27_C7548();
    virtual void fn_27_C75D8();
    virtual void fn_27_C7654();
};
struct Owner {
    int value;
    Class_20958* array;
};
extern "C" void fn_27_C428C(void*);
extern "C" void fn_27_C3E58(Owner* self) {
    self->value = -1;
    if (self->array) {
        int count = self->array->size__41soArrayContractibleTable_C12soStatusData_CFv();
        for (int i = 0; i < count; i++) {
            fn_27_C428C(self->array->fn_27_C7528(i));
        }
        self->array->fn_27_C7654();
    }
}