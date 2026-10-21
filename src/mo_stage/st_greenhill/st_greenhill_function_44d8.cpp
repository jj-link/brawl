#pragma force_active on
extern "C" {
extern const float lbl_72_rodata_6C;
extern unsigned char lbl_72_data_1A88[];

void fn_72_45FC(void*);
void fn_72_460C(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*),
                       unsigned long, int);
}

struct StObj {
    unsigned char pad[0x28];
    float x, y, z;
    unsigned char pad34[8];
    unsigned long reserved3c : 27;
    unsigned long flags3c : 5;
    unsigned long field40;
    unsigned char* data44;
    unsigned char* data48;
    unsigned long flags4c : 13;
    unsigned long reserved4c : 19;
};

extern "C" void* fn_72_44D8(StObj* self) {
    self->x = lbl_72_rodata_6C;
    self->y = lbl_72_rodata_6C;
    self->z = lbl_72_rodata_6C;
    self->flags3c = 0;

    unsigned char* base = lbl_72_data_1A88;
    self->data44 = base;
    self->data48 = base + 0x48;
    self->flags4c = 0;

    __construct_array((unsigned char*)self + 0x50,
                      fn_72_45FC, fn_72_460C, 8, 7);
    return self;
}
