#pragma force_active on
extern "C" const float lbl_27_rodata_400;
extern "C" const float lbl_27_rodata_404;
extern "C" char lbl_27_data_2E68[];

struct Flags {
    unsigned int high : 16;
    unsigned int value : 4;
    unsigned int middle : 8;
    unsigned int mode : 2;
    unsigned int enabled : 1;
    unsigned int last : 1;
};

struct Object {
    unsigned int unk0;
    void* unk4;
    unsigned char pad8[8];
    float unk10, unk14;
    unsigned char pad18[0x18];
    float unk30;
    unsigned char unk34;
    unsigned char pad35;
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

extern "C" void fn_27_2E818(Object* p) {
    p->unk40 = lbl_27_data_2E68;
    p->bytes.a = 0;
    p->bytes.b = 0;
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk10 = lbl_27_rodata_400;
    p->unk14 = lbl_27_rodata_400;
    p->unk30 = lbl_27_rodata_404;
    p->unk34 = 0;
    p->unk36 = 0;
    p->flags.value = 4;
    p->flags.mode = 0;
    p->flags.enabled = 1;
    p->flags.last = 0;
    p->unk3C |= 0x80000000;
}
