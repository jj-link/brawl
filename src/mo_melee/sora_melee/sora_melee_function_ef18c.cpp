#pragma force_active on
struct FnObj27 {
    char pad0[4];
    int field4;
    short field8;
    short fieldA;
};

extern "C" void fn_27_EF18C(FnObj27* p) {
    p->field4 = -1;
    p->field8 = 0;
    p->fieldA = -1;
}
