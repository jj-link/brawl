#pragma force_active on
extern const float lbl_61_rodata_140;
extern char lbl_61_data_2CD0[];

extern "C" void fn_61_9D24(void*);
extern "C" void* fn_61_9D34(void*, int);
extern "C" void __construct_array(
    void*, void (*)(void*), void (*)(void*), unsigned long, int);

struct Fzero {
    char pad[0x28];
    float x, y, z;
    char pad34[8];
    unsigned int keep3c : 27;
    unsigned int flags : 5;
    unsigned int field40;
    void* ptr44;
    void* ptr48;
    unsigned int flags4c : 13;
    unsigned int keep4c : 19;
    char array[7][8];
};

extern "C" Fzero* fn_61_9C00(Fzero* p) {
    p->x = lbl_61_rodata_140;
    p->y = lbl_61_rodata_140;
    p->z = lbl_61_rodata_140;
    p->flags = 0;
    p->ptr44 = lbl_61_data_2CD0;
    p->ptr48 = lbl_61_data_2CD0 + 0x48;
    p->flags4c = 0;
    __construct_array(
        p->array, fn_61_9D24, (void (*)(void*))fn_61_9D34, 8, 7);
    return p;
}
