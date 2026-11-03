#pragma force_active on
extern "C" void fn_80133B98(void*, int);
extern "C" const float lbl_27_rodata_400;

struct Flags {
    unsigned int high : 16;
    unsigned int value : 4;
    unsigned int middle : 8;
    unsigned int flag : 1;
    unsigned int mode : 1;
    unsigned int enabled : 1;
    unsigned int last : 1;
};

struct Object {
    unsigned int unk0;
    void* unk4;
    unsigned char pad8[8];
    float unk10, unk14, unk18, unk1C;
    unsigned char pad20[0x16];
    unsigned short unk36;
    union {
        Flags flags;
        struct {
            unsigned char a, b;
            unsigned short c;
        } bytes;
    };
    unsigned int unk3C;
    void* unk40;
};

extern "C" void fn_27_2E8F8(Object* p) {
    if (p->unk4) {
        fn_80133B98(p->unk4, 1);
        p->unk4 = 0;
    }
    p->flags.flag = 0;
    p->bytes.a = 0;
    p->bytes.b = 0;
    p->flags.value = 4;
    p->unk0 = 0;
    p->unk36 = 0;
    p->unk10 = lbl_27_rodata_400;
    p->unk14 = lbl_27_rodata_400;
    p->unk18 = lbl_27_rodata_400;
    p->unk1C = lbl_27_rodata_400;
    p->flags.mode = 0;
    p->flags.enabled = 1;
    p->flags.last = 0;
    p->unk3C |= 0x80000000;
}
