#pragma force_active on
class Class_2F8E8 {
public:
    virtual void fn_27_174D8C();
    virtual void fn_27_1744D4();
    virtual void fn_27_17496C();
    virtual void fn_27_73E4C(int);
};
class Class_20958 {
public:
    virtual void fn_27_C76A8();
    virtual Class_2F8E8** fn_27_C7528(int);
    virtual void fn_27_C7538();
    virtual int size__41soArrayContractibleTable();
};
class Owner {
public:
    char pad0[0x30];
    Class_20958* container;
    int index;
    char pad1[0x7d - 0x38];
    unsigned char state;
};
extern "C" void fn_27_73DA4(Owner* self, int arg) {
    if (self->state == 1) {
        int idx = self->index;
        if (idx >= 0) {
            if (idx < self->container->size__41soArrayContractibleTable()) {
                Class_2F8E8* item = *self->container->fn_27_C7528(idx);
                if (item) {
                    item->fn_27_73E4C(arg);
                }
            }
        }
    }
}