#pragma force_active on
extern const float lbl_77_rodata_80;
extern unsigned char lbl_77_data_1628[];

extern "C" void fn_77_3668(int*);
extern "C" void* fn_77_3678(void*, int);
extern "C" void __construct_array(
    void*, void (*)(void*), void (*)(void*), unsigned long, int);

struct Object {
    unsigned char pad[0x28];
    float x, y, z;
    unsigned char pad34[8];
    unsigned int keep3c : 27;
    unsigned int flags3c : 5;
    unsigned int unk40;
    void* ptr44;
    void* ptr48;
    unsigned int flags4c : 13;
    unsigned int keep4c : 19;
    unsigned char elements[7][8];
};

extern "C" Object* fn_77_3544(Object* p) {
    p->x = lbl_77_rodata_80;
    p->y = lbl_77_rodata_80;
    p->z = lbl_77_rodata_80;
    p->flags3c = 0;
    p->ptr44 = lbl_77_data_1628;
    p->ptr48 = lbl_77_data_1628 + 0x48;
    p->flags4c = 0;
    __construct_array(p->elements, (void (*)(void*))fn_77_3668,
                      (void (*)(void*))fn_77_3678, 8, 7);
    return p;
}
