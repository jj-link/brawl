#pragma force_active on
extern const float lbl_73_rodata_88;
extern unsigned char lbl_73_data_45D8[];

extern "C" void fn_73_A070(void*);
extern "C" void fn_73_A080(void*);
extern "C" void __construct_array(
    void*, void (*)(void*), void (*)(void*), unsigned long, int);

struct Object {
    unsigned char pad0[0x28];
    float x, y, z;
    unsigned char pad34[8];
    unsigned int unused3c : 27;
    unsigned int flags3c : 5;
    unsigned int unk40;
    void* ptr44;
    void* ptr48;
    unsigned int flags4c : 13;
    unsigned int unused4c : 19;
    unsigned char array[7][8];
};

extern "C" Object* fn_73_9C84(Object* p) {
    float v = lbl_73_rodata_88;
    p->x = v;
    p->y = v;
    p->z = v;
    p->flags3c = 0;
    p->ptr44 = lbl_73_data_45D8;
    p->ptr48 = lbl_73_data_45D8 + 0x48;
    p->flags4c = 0;
    __construct_array(p->array, fn_73_A070, fn_73_A080, 8, 7);
    return p;
}
