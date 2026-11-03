#pragma force_active on
class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int slot6();
};

struct Entry { soNullable* value; };

class Class_20958 {
public:
    virtual void fn_27_C76A8();
    virtual Entry* fn_27_C7528(int);
    virtual void fn_27_C7538();
    virtual int size__41soArrayContractibleTable_C12soStatusData_CFv();
    virtual void fn_27_C76F0();
    virtual void fn_27_C74E8();
    virtual void fn_27_C7548();
};

struct Object {
    char pad[0x2c];
    Class_20958* array;
};

extern "C" soNullable* fn_27_96E6C(Object* self, int kind, int index) {
    int count = 0;
    for (int i = 0; i < self->array->size__41soArrayContractibleTable_C12soStatusData_CFv(); i++) {
        if (self->array->fn_27_C7528(i)->value != 0) {
            if (kind == self->array->fn_27_C7528(i)->value->slot6()) {
                if (index == count) {
                    return self->array->fn_27_C7528(i)->value;
                }
                count++;
            }
        }
    }
    return 0;
}