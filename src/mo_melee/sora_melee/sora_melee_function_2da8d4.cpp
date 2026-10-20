#pragma force_active on
extern char lbl_27_data_2BEE8[];
extern const float lbl_27_rodata_6378;

struct Object {
    void* vtable;
    unsigned char flag;
    float x;
    float y;
};

extern "C" void fn_27_2DA8D4(Object* p) {
    p->vtable = lbl_27_data_2BEE8;
    p->flag = 0;
    p->x = lbl_27_rodata_6378;
    p->y = lbl_27_rodata_6378;
}
