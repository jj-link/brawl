#pragma force_active on
extern "C" {
extern const float lbl_78_rodata_E0;
extern char lbl_78_data_1CF0[];
void fn_78_4D84(void*);
void* fn_78_4D94(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

struct Object {
    char pad00[0x28];
    float x, y, z;
    char pad34[8];
    unsigned int keep3c : 27;
    unsigned int flags3c : 5;
    unsigned int pad40;
    void* table44;
    void* table48;
    unsigned int flags4c : 13;
    unsigned int keep4c : 19;
    char array[56];
};

extern "C" void* fn_78_4C60(void* self) {
    Object* p = (Object*)self;
    p->x = lbl_78_rodata_E0;
    p->y = lbl_78_rodata_E0;
    p->z = lbl_78_rodata_E0;
    p->flags3c = 0;
    p->table44 = lbl_78_data_1CF0;
    p->table48 = lbl_78_data_1CF0 + 0x48;
    p->flags4c = 0;
    __construct_array(p->array, (void (*)(void*))fn_78_4D84,
                      (void (*)(void*))fn_78_4D94, 8, 7);
    return self;
}
