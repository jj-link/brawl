#pragma force_active on
extern const float lbl_52_rodata_12C[5];
extern unsigned char lbl_52_data_1BC0[0x90];

extern "C" void fn_52_6F70(int*);
extern "C" void* fn_52_6F80(void*, int);
extern "C" void __construct_array(
    void*, void (*)(void*), void (*)(void*), unsigned long, int);

struct Object {
    unsigned char pad0[0x28];
    float x, y, z;
    unsigned char pad34[8];
    unsigned int : 27;
    unsigned int flags3C : 5;
    unsigned int field40;
    void* field44;
    void* field48;
    unsigned int flags4C : 13;
    unsigned int : 19;
    unsigned char array[0x38];
};

extern "C" Object* fn_52_6E4C(Object* p) {
    p->x = lbl_52_rodata_12C[0];
    p->y = lbl_52_rodata_12C[0];
    p->z = lbl_52_rodata_12C[0];
    p->flags3C = 0;
    p->field44 = lbl_52_data_1BC0;
    p->field48 = lbl_52_data_1BC0 + 0x48;
    p->flags4C = 0;
    __construct_array(
        p->array,
        (void (*)(void*))fn_52_6F70,
        (void (*)(void*))fn_52_6F80,
        8, 7);
    return p;
}
