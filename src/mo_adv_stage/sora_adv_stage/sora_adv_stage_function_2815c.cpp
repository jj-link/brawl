#pragma force_active on
extern "C" {
extern const float lbl_40_rodata_420;
extern char lbl_40_data_85B0[];
void fn_40_1DF04(void*);
void fn_40_1DF14(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

struct Object {
    char pad00[0x28];
    float x, y, z;
    char pad34[8];
    unsigned int keep3c : 27;
    unsigned int flags3c : 5;
    char pad40[4];
    void* table44;
    void* table48;
    unsigned int flags4c : 13;
    unsigned int keep4c : 19;
    char array[56];
};

extern "C" void* fn_40_2815C(void* self) {
    Object* p = (Object*)self;
    p->x = lbl_40_rodata_420;
    p->y = lbl_40_rodata_420;
    p->z = lbl_40_rodata_420;
    p->flags3c = 0;
    p->table44 = lbl_40_data_85B0;
    p->table48 = lbl_40_data_85B0 + 0x48;
    p->flags4c = 0;
    __construct_array(p->array, (void (*)(void*))fn_40_1DF04,
                      (void (*)(void*))fn_40_1DF14, 8, 7);
    return self;
}
