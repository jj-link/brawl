#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

union Flags {
    u8 raw;
    struct {
        u8 a : 1;
        u8 r : 7;
    } bits;
};

struct Obj {
    void* unk0;
    int unk4;
    u32 hi : 8;
    u32 lo : 24;
    char pad0C[0x78];
    int unk84;
    short unk88;
    char pad8A[2];
    int unk8C;
    short unk90;
    char pad92[2];
    Flags f94;
    u8 unk95;
    char pad96[2];
    float unk98;
    float unk9C;
    float unkA0;
    float unkA4;
    float unkA8;
    float unkAC;
    float unkB0;
    float unkB4;
    float unkB8;
    char padBC[0xA0];
    float unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178;
    float unk17C, unk180, unk184, unk188, unk18C, unk190, unk194;
};

extern "C" void fn_800A2CE0(void*);
extern "C" void fn_80018610(void*);
extern "C" char* getManager__15gfCameraManagerFv();
extern const float lbl_805A1E80;
extern const float lbl_805A1E84;
extern const float lbl_805A1E88;
extern const float lbl_805A1E8C;
extern const float lbl_805A1E90;
extern const float lbl_805A1E94;
extern const float lbl_805A1E98;
extern const float lbl_805A1E9C;
extern const float lbl_805A1EA0;

extern "C" void fn_8009F78C(Obj* self) {
    self->unk88 = 0;
    self->hi = 0;
    self->unk84 = 0;
    self->unk90 = 0;
    self->unk8C = 0;
    self->unk17C = lbl_805A1E80;
    self->unk180 = lbl_805A1E84;
    self->unk184 = lbl_805A1E80;
    self->f94.bits.a = 0;
    self->f94.raw |= 0x18;
    self->f94.raw &= ~0x60;
    self->f94.raw &= ~0x06;
    self->f94.raw |= 0x01;
    self->unk95 |= 0x80;
    self->unkB0 = lbl_805A1E80;
    self->unkB4 = lbl_805A1E80;
    self->unkA4 = lbl_805A1E80;
    self->unkA0 = lbl_805A1E80;
    self->unk9C = lbl_805A1E80;
    self->unkAC = lbl_805A1E80;
    self->unkA8 = lbl_805A1E80;
    self->unkB8 = lbl_805A1E80;
    fn_800A2CE0((char*)self + 0xC);
    fn_800A2CE0((char*)self + 0x48);
    self->unk15C = lbl_805A1E88;
    self->unk160 = lbl_805A1E8C;
    self->unk164 = lbl_805A1E90;
    self->unk168 = lbl_805A1E94;
    self->unk16C = lbl_805A1E88;
    self->unk170 = lbl_805A1E8C;
    self->unk174 = lbl_805A1E90;
    self->unk178 = lbl_805A1E94;
    self->unk188 = lbl_805A1E98;
    self->unk18C = lbl_805A1E9C;
    self->unk190 = lbl_805A1E9C;
    self->unk194 = lbl_805A1E98;
    if (self->unk0 != 0) {
        fn_80018610(self->unk0);
    }
    char* m = getManager__15gfCameraManagerFv() + 0x134;
    if (m != 0) {
        fn_80018610(m);
        *(float*)(m + 0xE4) = lbl_805A1EA0;
    }
}
