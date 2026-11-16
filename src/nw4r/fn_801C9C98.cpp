#include <types.h>
#include <revolution/OS/OSMutex.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(s32);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(s32, f32);
    virtual void slot12();
    virtual void slot13();
    virtual u32 slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18(u32);
    virtual void slot19(u32);
    virtual void slot20(u32);

    u8* f4;
    u8 pad8[0x208];
};

struct Ctx {
    u8 pad0[0x10];
    void* f10;
    u8 pad14[0x8];
    u32 f1c;
    u8 pad20[0x1c];
    u32 f3c;
    u32 f40;
};

struct Arg2 {
    u32 id;
    u8 pad4[8];
    s32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
};

struct Arg3 {
    u32 f0;
    u8 pad4[4];
    u32 f8;
    u32 fc;
    u8 f10;
};

extern "C" {
u32 fn_801BFF28(void*);
void fn_801C2E84(void*, u32);
void* fn_801C2EF0(void*);
s32 fn_801C43A4(void*, u32, u32, u32, void*);
void fn_801C440C(void*, void*, u32, s32, s32);
void fn_801C4474(void*, void*, u32, s32, s32);
void fn_801C4738(void*, u32);
void fn_801C4740(void*, u8);
Object_vptr_0* fn_801C6C3C(void*, u32, void*, s32);
s32 fn_801C96B8(void*, u32);
}

extern f32 lbl_805A3620;

inline u32 getFreeSize(u8* heap) {
    OSMutex* mutex = (OSMutex*)(heap + 4);
    OSLockMutex(mutex);
    u32 size = fn_801BFF28(heap + 0x1c);
    OSUnlockMutex(mutex);
    return size;
}

extern "C" s32 fn_801C9C98(Ctx* self, Object_vptr_0* arg1, Arg2* arg2, Arg3* arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 sp8[2];
    s32 r29 = fn_801C96B8(self, arg2->id);
    Object_vptr_0* r28;
    s32 r26 = arg5;
    r28 = NULL;

    if (r29 == 0) {
        u8* r31 = arg1->f4;
        if (r31 == NULL) {
            return 4;
        }
        r28 = fn_801C6C3C(self->f10, arg2->id, (u8*)arg1 + 0x210, 0x200);
        if (r28 == NULL) {
            return 6;
        }
        u32 r31v = getFreeSize(r31);
        if (r31v < r28->slot14()) {
            r28->slot2();
            return 5;
        }
    }

    s32 r = fn_801C43A4(arg1, self->f1c, arg3->f8, arg6, self->pad20);
    while (r != 0) {
        if (r == 1) {
        u32 t = self->f3c;
        if (t == 1) {
            if (r28 != NULL) {
                r28->slot2();
            }
            return 1;
        }
        Object_vptr_0* obj;
        if (t == 0) {
            obj = NULL;
        } else {
            obj = (Object_vptr_0*)(self->f40 - 0xb8);
        }
        if (arg1 == obj) {
            if (r28 != NULL) {
                r28->slot2();
            }
            return 1;
        }
        obj->slot4(0);
        r = fn_801C43A4(arg1, self->f1c, arg3->f8, arg6, self->pad20);
        } else {
            return 0xFF;
        }
    }

    arg1->slot11(arg2->f0c, (f32)arg2->f0c / lbl_805A3620);
    fn_801C4738(arg1, arg3->fc);
    fn_801C4740(arg1, arg3->f10);
    arg1->slot18(arg2->f10);
    arg1->slot19(arg2->f14);
    arg1->slot20(arg2->f18);

    s32 r30;
    switch (arg4) {
    case 0:
        r30 = 1;
        break;
    case 1:
        r30 = 0;
        break;
    case 2:
        r30 = 0;
        r26 = 0;
        break;
    default:
        r30 = 0;
        r26 = 0;
        break;
    }

    if (r29 != 0) {
        fn_801C2E84(sp8, r29);
        fn_801C440C(arg1, fn_801C2EF0(sp8), arg3->f0, r30, r26);
    } else {
        fn_801C4474(arg1, r28, arg3->f0, r30, r26);
    }
    return 0;
}
