#pragma force_active on
#include <types.h>

extern "C" {
u32 fn_8015D804(void*);
void DCFlushRange(void*, u32);
void fn_8015D8B8(void*, void*, u32);
void fn_801E0CC0();
int fn_801D7AD8();
void fn_80046A64(void*, u32, u32, void*, u32*, u32, void*, u32, void*, void*, void*);
void fn_800470A8(void*, u32, void*, u32);
void fn_801A5414(void*, u32, void**, u32);
void fn_8015D8C0(void*, void*, u32);
void fn_8015D874();
s32 fn_801AB384(void*);
void fn_801B2E2C(void*);
void fn_80197AFC(void*, void*, u32);
void fn_80197A40(void*, u32);
}

struct Data {
    u8 pad0[0x40];
    u8 values[0x24];
    u32 offset;
};

struct Base {
    u8 values[0x24];
    u32 offset;
};

struct Opt {
    u32 a;
    u8 b;
    u16 c;
};

struct HandlerObj {
    virtual void vf0();
    virtual void vf1(u32, void*, u32, void*);
};

struct Self {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7(u32, void*);
    virtual void vf8();
    virtual void vf9();
    virtual void vf10(void*, void*);

    u8 pad4[0x3c - 0x4];
    u8 field3C[0xd4 - 0x3c];
    HandlerObj* h;
    u8 flagsD8;
    u8 padD9;
    u16 flagsDA;
    u8 padDC[0xe8 - 0xdc];
    Data* data;
    void* buffer;
    u32 fieldF0;
    u8 padF4[0x104 - 0xf4];
    u32 flags104;
    u32 field108;
    u32 field10C;
    u8 pad110[0x11c - 0x110];
    Opt opt;
    u32 field124;
    u32 field128;
    u8 pad12C[0x13c - 0x12c];
    u32 flags13C;
    u8 pad140[0x148 - 0x140];
    void* field148;
};

extern "C" void fn_800471A4(Self* self, s32 arg1, void* arg2, void* arg3, void* arg4, int arg5, int arg6, u32 arg7) {
    u32 sp34;
    u32 sp30;
    u32 sp2C;
    u32 sp28;
    u32 sp24;
    u32 sp20;
    u32 sp1C;
    s32 sp18 = arg1;

    HandlerObj* h = self->h;
    if (h != NULL && (self->flagsDA & 1) && (self->flagsD8 & 1)) {
        h->vf1(1u, self, (u32)sp18, arg2);
    }

    self->vf10(arg2, &sp18);
    u32 v = (u32)sp18;

    h = self->h;
    if (h != NULL && (self->flagsDA & 1) && (self->flagsD8 & 2)) {
        h->vf1(2u, self, v, arg2);
    }

    Base* b = (Base*)((char*)self->data + 0x40);
    char* base = (char*)b;
    u32 count = *(u32*)(base + b->offset);
    void* buffer;
    u32* flagsP = &self->flags104;
    u32 var_r28 = 0;

    if (arg5 != 0 && count > 8 && count < 0x156 &&
        (var_r28 = fn_8015D804(base)) == 1) {
        u32 size = count * 0x30;
        DCFlushRange(self->buffer, size);
        fn_8015D8B8((void*)0xE0000000, self->buffer, size);

        while (fn_801D7AD8() != 0) {
            fn_801E0CC0();
        }

        buffer = (void*)0xE0000000;
    } else {
        buffer = self->buffer;
        *flagsP &= ~1u;
    }

    *flagsP &= ~2u;

    s32 r21 = fn_801AB384(self);

    u32 var_r20 = 0xF0000000;
    self->vf7(0x20001u, &sp34);
    if (r21 == 1) {
        var_r20 = 0x30000000;
    } else if (r21 == 2) {
        var_r20 = 0;
    }
    if (sp34 != 0) {
        var_r20 |= 0x08000000;
    }

    u8 ob;
    u16 oc;
    u32 oa = self->opt.a;
    if (oa != 0) {
        oc = self->opt.c;
        ob = self->opt.b;
        Opt sp38;
        sp38.a = oa;
        sp38.b = ob;
        sp38.c = oc;
        u32 f124 = self->field124;
        sp30 = (u32)self->data;
        fn_80046A64(buffer, self->fieldF0, self->field108, &self->field3C,
                    &sp30, f124, &sp38, var_r20, arg3, arg4, flagsP);
    } else {
        u32 f124 = self->field124;
        sp2C = (u32)self->data;
        fn_80046A64(buffer, self->fieldF0, self->field108, &self->field3C,
                    &sp2C, f124, NULL, var_r20, arg3, arg4, flagsP);
    }

    if (arg7 == 1 && !(*flagsP & 4)) {
        sp28 = (u32)self->data;
        fn_800470A8(buffer, self->field108, &sp28, (u32)arg4);
        *flagsP |= 4;
    }

    if (arg6 != 0) {
        u32 f10c = self->field10C;
        if (f10c != 0) {
            sp24 = (u32)self->data;
            fn_801A5414(buffer, self->fieldF0, (void**)&sp24, f10c);
        }
    }

    if (var_r28 != 0) {
        fn_8015D8C0(self->buffer, (void*)0xE0000000, count * 0x30);
        fn_8015D874();
    }

    if (arg7 == 1) {
        u32 f = self->flags13C;
        if (!(f & 2) && (f & 1)) {
            fn_801B2E2C(self);
        }
        u32 f128 = self->field128;
        if (f128 != 0) {
            if (self->field148 != 0) {
                sp20 = (u32)self->data;
                fn_80197AFC(self->field148, &sp20, f128);
                self->flags13C |= 1;
            } else {
                sp1C = (u32)self->data;
                fn_80197A40(&sp1C, f128);
            }
        }
        u32 v2 = (u32)sp18;
        h = self->h;
        if (h != NULL && (self->flagsDA & 1) && (self->flagsD8 & 4)) {
            h->vf1(4u, self, v2, arg2);
        }
    }
}
