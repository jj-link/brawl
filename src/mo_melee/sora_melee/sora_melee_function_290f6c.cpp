#pragma force_active on
extern "C" {
struct Obj {
    unsigned int *a;
    unsigned int *b;
    unsigned int value;
};

extern unsigned char lbl_27_data_55F48[];

void fn_27_290F6C(Obj *obj) {
    unsigned int *base = (unsigned int *)lbl_27_data_55F48;
    unsigned int *next = base + 18;
    unsigned int value = obj->value;
    obj->a = base;
    obj->b = next;
    obj->value = value & 0xFFFF;
}
}
