#include <types.h>
#pragma force_active on

struct Inner {
    void* vtable;
    char pad[2];
    unsigned short flag;
};

struct Self {
    void* vtable;
    char pad04[0x68];
    int unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    char pad90[0x10];
    void* unkA0;
    char padA4[2];
    unsigned short unkA6;
    unsigned char unkA8;
    char padA9[0x10B];
    int unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8;
    int unk1CC, unk1D0, unk1D4, unk1D8, unk1DC, unk1E0;
};

struct Value {
    int x;
};

extern "C" void fn_802F0438(Self*, int*);

extern unsigned char lbl_80487CD0[];
extern unsigned char lbl_80487D38[];
extern unsigned char lbl_80487DA0[];
extern unsigned char lbl_80487E08[];
extern unsigned char lbl_80487E28[];
extern unsigned char lbl_80488020[];
extern unsigned char lbl_80488088[];
extern unsigned char lbl_80488100[];
extern unsigned char lbl_80488170[];

inline void base(Self* self, Value value) {
    fn_802F0438(self, &value.x);
}

extern "C" Self* fn_802E1184(Self* self, const Value& arg1) {
    base(self, arg1);

    Inner* inner = (Inner*)((char*)self + 0xA0);

    self->vtable = lbl_80487E08;
    self->unk6C = 0;
    self->unk70 = 0;
    self->unk74 = (int)0x80000000;
    self->unk78 = 0;
    self->unk7C = 0;
    self->unk80 = (int)0x80000000;
    self->unk84 = 0;
    self->unk88 = 0;
    self->unk8C = (int)0x80000000;
    inner->flag = 1;
    inner->vtable = lbl_80487E28;
    self->unk1B4 = 0;
    self->unk1B8 = 0;
    self->unk1BC = (int)0x80000000;
    self->unk1C0 = 0;
    self->unk1C4 = 0;
    self->unk1C8 = (int)0x80000000;
    self->unk1CC = 0;
    self->unk1D0 = 0;
    self->unk1D4 = (int)0x80000000;
    self->unk1D8 = 0;
    self->unk1DC = 0;
    self->unk1E0 = (int)0x80000000;

    if (arg1.x) {
        unsigned char type = self->unkA8;
        switch (type) {
        case 2:
            if (inner) {
                inner->flag = 1;
                inner->vtable = lbl_80488170;
            }
            break;
        case 3:
            if (inner) {
                inner->flag = 1;
                inner->vtable = lbl_80487DA0;
            }
            break;
        case 4:
            if (inner) {
                inner->flag = 1;
                inner->vtable = lbl_80488020;
            }
            break;
        case 5:
            if (inner) {
                inner->flag = 1;
                inner->vtable = lbl_80487D38;
            }
            break;
        case 6:
            if (inner) {
                inner->flag = 1;
                inner->vtable = lbl_80488100;
            }
            break;
        case 7:
            if (inner) {
                inner->flag = 1;
                inner->vtable = lbl_80488088;
            }
            break;
        case 8:
            if (inner) {
                inner->flag = 1;
                inner->vtable = lbl_80487CD0;
            }
            break;
        }
    }

    return self;
}
