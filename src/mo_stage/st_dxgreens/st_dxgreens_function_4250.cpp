#pragma force_active on
extern "C" {
extern const float lbl_79_rodata_44;
extern unsigned char lbl_79_data_2048[];

void fn_79_46B0(void*);
void fn_79_46C0(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

struct S {
    char pad0[0x28];
    float x, y, z;
    char pad34[8];
    unsigned int unused3c : 27;
    unsigned int flags : 5;
    unsigned int pad40;
    void* a;
    void* b;
    unsigned int flags4c : 13;
    unsigned int unused4c : 19;
    char array[56];
};

extern "C" void* fn_79_4250(S* s) {
    s->x = lbl_79_rodata_44;
    s->y = lbl_79_rodata_44;
    s->z = lbl_79_rodata_44;
    s->flags = 0;
    s->a = lbl_79_data_2048;
    s->b = lbl_79_data_2048 + 0x48;
    s->flags4c = 0;
    __construct_array(s->array, fn_79_46B0, fn_79_46C0, 8, 7);
    return s;
}
