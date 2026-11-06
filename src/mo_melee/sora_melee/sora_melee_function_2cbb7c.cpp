#include <types.h>
#pragma force_active on

struct S {
    char pad0[0xc];
    s32 divisor;
    s32 unk3c6c;
    char pad1[0x20];
    s32 rem;
    s32 quot;
};

struct Obj {
    char pad0[0x10];
    s32 unk3c18;
    char pad1[0x3c3c - 0x3c1c];
    s32 unk3c3c;
    s32 unk3c40;
    char pad2[0x54 - 0x3c];
};

struct Self {
    char pad0[0x3c08];
    Obj obj;
    S s;
    char pad1[0x3cb0 - 0x3c98];
    s32 unk3cb0;
    s32 unk3cb4;
    char pad2[0x3cc0 - 0x3cb8];
    s32 unk3cc0;
    s32 unk3cc4;
    char pad3[0x3ccc - 0x3cc8];
    s32 unk3ccc;
    s32 unk3cd0;
};

extern "C" {
void fn_27_2D6974(void*, int, int, int, int);
void fn_27_2C9714(int, int);
void fn_27_2D6B44(void*);
void fn_27_2D6BFC(S*, int);
void fn_27_2D6C18(void*, int, int);
}
extern void* lbl_27_bss_7328;

extern "C" void fn_27_2CBB7C(Self* self, int arg1) {
    self->unk3ccc = arg1;
    self->unk3cc4 = 0;
    self->unk3cc0 = 0;
    fn_27_2D6B44(&self->obj);
    fn_27_2D6C18(&self->obj, 0, 0);
    switch (arg1) {
    case 0: {
        int idx = self->obj.unk3c3c * self->obj.unk3c18 + self->obj.unk3c40;
        char* task = (char*)lbl_27_bss_7328;
        if (idx < *(int*)(task + 0x42dc)) {
            char* record = *(char**)(task + 0x2edc + idx * 4);
            fn_27_2C9714(*(int*)record, *(short*)(record + 4));
        } else {
            fn_27_2C9714(0, -1);
        }
        break;
    }
    case 1: {
        fn_27_2D6974(&self->s, 3, 3, 1, 1);
        switch (self->unk3cb0) {
        case 1:
            fn_27_2D6BFC(&self->s, 1);
            break;
        case 0:
            fn_27_2D6BFC(&self->s, 2);
            break;
        case 5:
            fn_27_2D6BFC(&self->s, 3);
            break;
        default:
            fn_27_2D6BFC(&self->s, 0);
            break;
        }
        fn_27_2D6B44(&self->s);
        int idx = self->s.quot + self->s.rem * self->s.unk3c6c;
        if (idx == 3) {
            fn_27_2C9714(0, 0x21);
        } else {
            fn_27_2C9714(0, idx + 0x18);
        }
        break;
    }
    case 2: {
        char* task = (char*)lbl_27_bss_7328;
        if (*(unsigned char*)(task + 0x44) == 0) {
            fn_27_2D6974(&self->s, 4, 4, 1, 1);
            switch (self->unk3cb4) {
            case 0:
                fn_27_2D6BFC(&self->s, 1);
                break;
            case 1:
                fn_27_2D6BFC(&self->s, 2);
                break;
            case 2:
                fn_27_2D6BFC(&self->s, 3);
                break;
            case 3:
                fn_27_2D6BFC(&self->s, 4);
                break;
            default:
                fn_27_2D6BFC(&self->s, 0);
                break;
            }
            fn_27_2D6B44(&self->s);
            fn_27_2C9714(0, self->s.quot + self->s.rem * self->s.unk3c6c + 0x1D);
        } else {
            fn_27_2D6974(&self->s, 0xA, 0xA, 2, 1);
            fn_27_2D6BFC(&self->s, self->unk3cd0);
            fn_27_2D6B44(&self->s);
            fn_27_2C9714(0, 0x23);
        }
        break;
    }
    case 3:
        fn_27_2C9714(0, 0x22);
        break;
    }
}