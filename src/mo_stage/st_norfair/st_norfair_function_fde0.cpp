#pragma force_active on

#define VIRTUAL_1(n) virtual void unused##n();
#define VIRTUAL_2(n) VIRTUAL_1(n##a) VIRTUAL_1(n##b)
#define VIRTUAL_4(n) VIRTUAL_2(n##a) VIRTUAL_2(n##b)
#define VIRTUAL_8(n) VIRTUAL_4(n##a) VIRTUAL_4(n##b)
#define VIRTUAL_16(n) VIRTUAL_8(n##a) VIRTUAL_8(n##b)
#define VIRTUAL_32(n) VIRTUAL_16(n##a) VIRTUAL_16(n##b)
#define VIRTUAL_64(n) VIRTUAL_32(n##a) VIRTUAL_32(n##b)

struct Vec3 {
    float x, y, z;
};

struct Obj {
    unsigned char padding[0x3C];

    VIRTUAL_64(a)
    VIRTUAL_32(b)
    VIRTUAL_16(c)
    VIRTUAL_4(d)
    VIRTUAL_2(e)
    VIRTUAL_1(f)
    virtual void call(unsigned int, unsigned int, Vec3*);

    unsigned char padding1[0x148];
    unsigned int arr[18];
    unsigned char pad2;
    unsigned char flag;
};

extern "C" float lbl_54_rodata_198;
extern "C" float lbl_54_rodata_1C0;

extern "C" void fn_54_FDE0(Obj* self) {
    if (self->flag != 1) {
        Vec3 v;
        float b;
        float a;
        a = lbl_54_rodata_198;
        b = lbl_54_rodata_1C0;

        for (unsigned char i = 0; i < 0x12; ++i) {
            v.x = a;
            v.y = b;
            v.z = a;
            self->call(i, self->arr[i], &v);
        }

        self->flag = 1;
    }
}
