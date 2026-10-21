#pragma force_active on

extern "C" {
extern const float lbl_54_rodata_8C;
extern char lbl_54_data_1D98[];

void fn_54_5BDC(void*);
void fn_54_5BEC(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*),
                       unsigned long, int);
}

struct S {
    char pad[0x28];
    float x, y, z;
    char pad34[8];
    unsigned long : 27;
    unsigned long flags3c : 5;
    unsigned long unk40;
    void* p44;
    void* p48;
    unsigned long flags4c : 13;
    unsigned long : 19;
};

extern "C" S* fn_54_5AB8(S* self) {
    self->x = lbl_54_rodata_8C;
    self->y = lbl_54_rodata_8C;
    self->z = lbl_54_rodata_8C;
    self->flags3c = 0;
    char* base = lbl_54_data_1D98;
    self->p44 = base;
    self->p48 = base + 0x48;
    self->flags4c = 0;
    __construct_array((char*)self + 0x50, fn_54_5BDC, fn_54_5BEC, 8, 7);
    return self;
}
