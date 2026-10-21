#pragma force_active on
extern const float lbl_50_rodata_C8;
extern char lbl_50_data_1F38[];

extern "C" void fn_50_5D40(void*);
extern "C" void* fn_50_5D50(void*, int);
extern "C" void __construct_array(
    void*, void (*)(void*), void (*)(void*), unsigned long, int);

struct Object {
    char pad0[0x28];
    float x, y, z;
    char pad34[8];
    unsigned int preserved3c : 27;
    unsigned int flags3c : 5;
    unsigned int field40;
    void* field44;
    void* field48;
    unsigned int flags4c : 13;
    unsigned int preserved4c : 19;
    char array[7][8];
};

extern "C" Object* fn_50_5C1C(Object* p) {
    float value = lbl_50_rodata_C8;
    p->x = value;
    p->y = value;
    p->z = value;
    p->flags3c = 0;
    p->field44 = lbl_50_data_1F38;
    p->field48 = lbl_50_data_1F38 + 0x48;
    p->flags4c = 0;
    __construct_array(
        p->array, fn_50_5D40, (void (*)(void*))fn_50_5D50, 8, 7);
    return p;
}
