#pragma force_active on
class ecMgr;
extern ecMgr* g_ecMgr;

extern "C" void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* __construct_new_array(void*, void (*)(), void*, unsigned long, int);
extern "C" void __dla__FPv(void*);
extern "C" int fn_8005F79C(ecMgr*);
extern "C" void fn_80065E60();
extern "C" void fn_80065BF8();

extern const float lbl_805A1990;
extern const float lbl_805A1994;

struct Vec3f {
    float x, y, z;

    Vec3f(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct Obj {
    void* unk0;
    void* unk4;
    unsigned short unk8;
    unsigned short unkA;
    unsigned short unkC;
    unsigned char unkE;
    unsigned char unkF;
    unsigned long unk10;
    float unk14;
    float unk18;
    unsigned char pad1C[0x10];
    unsigned long unk2C;
    unsigned char pad30[8];
    int unk38;
    int unk3C;
    unsigned char pad40[0xC];
    Vec3f unk4C;
    Vec3f unk58;
    Vec3f unk64;
    unsigned char unk70;
    unsigned char pad71[3];
    float unk74;
    unsigned char pad78[4];
    unsigned long unk7C;
};

extern "C" int fn_80065C98(Obj* self) {
    self->unk0 = 0;
    self->unk4 = 0;
    if (self->unk8 - 1 >= 2) {
        self->unk0 = __construct_new_array(
            __nwa__FUlQ25Heaps8HeapType(self->unk8 * 0x18 + 0x10, 3),
            fn_80065E60, 0, 0x18, self->unk8);
        if (self->unk70 != 0) {
            self->unk4 = __construct_new_array(
                __nwa__FUlQ25Heaps8HeapType(self->unk8 * 0xC + 0x10, 3),
                fn_80065BF8, 0, 0xC, self->unk8);
            if (self->unk4 == 0) {
                if (self->unk0) {
                    if (self->unk0)
                        __dla__FPv((char*)self->unk0 - 0x10);
                    self->unk0 = 0;
                }
            } else {
                Vec3f v(lbl_805A1990, lbl_805A1990, lbl_805A1994);
                self->unk64 = v;
            }
        }
    }
    self->unkF = 0;
    self->unk10 = 0;
    self->unkE = 0;
    if (fn_8005F79C(g_ecMgr) != 0) {
        self->unkE = self->unkE | 8;
    }
    self->unk38 = -1;
    self->unk3C = -1;
    self->unkA = 0;
    self->unkC = 0;
    self->unk2C = 0;
    ((unsigned char*)self)[0x30] = ((unsigned char*)self)[0x38];
    ((unsigned char*)self)[0x31] = ((unsigned char*)self)[0x39];
    ((unsigned char*)self)[0x32] = ((unsigned char*)self)[0x3A];
    ((unsigned char*)self)[0x33] = ((unsigned char*)self)[0x3B];
    ((unsigned char*)self)[0x34] = ((unsigned char*)self)[0x3C];
    ((unsigned char*)self)[0x35] = ((unsigned char*)self)[0x3D];
    ((unsigned char*)self)[0x36] = ((unsigned char*)self)[0x3E];
    ((unsigned char*)self)[0x37] = ((unsigned char*)self)[0x3F];
    self->unk14 = lbl_805A1994;
    self->unk74 = lbl_805A1994;
    Vec3f z(lbl_805A1990, lbl_805A1990, lbl_805A1990);
    self->unk58 = z;
    self->unk4C = z;
    self->unk7C = 0;
    self->unk18 = lbl_805A1990;
    return 1;
}
