#include <gf/gf_heap_manager.h>
#include <gf/gf_pad_status.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_thread.h>
#include <gm/gm_global.h>
#include <revolution/OS/OSThread.h>
#include <revolution/GX/GXTypes.h>
#include <types.h>
#pragma force_active on
extern "C" void __dt__8gfThreadFv(void*, int);
extern "C" void __dl__FPv(void*);
struct ThreadEx {
    char pad[0x340];
    union {
        struct { u32 m340a : 8; u32 m340b : 8; u32 m340c : 16; };
        struct { u16 m340; u16 m342; };
    };
    u16 m344;
    char pad346[2];
    u32 m348;
    u32 m34c;
    void* m350;
    char pad354[4];
    void* m358;
};
struct Self {
    char pad00[0x60];
    int result;
    int counter;
    char pad68[0x1C];
    void* buffer84;
    unsigned char* buffer88;
    char pad8c[0x10];
    char object9c[8];
    void* objecta4;
    char pada8[0x14];
    void* objectbc;
    int state;
    gfThread* thread;
    int c8;
    int cc;
    char padd0[4];
    int d4;
};
struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(const Vec2& other) { x = other.x; y = other.y; }
};
struct PadCopy {
    int words[6];
    Vec2 vectors[3];
    unsigned char b0, b1, b2, b3, b4, b5, b6, b7, b8;
    int last;
};
static inline gfPadStatus getRaw() {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xF0, &status);
    return status;
}
static inline int getDirection() {
    PadCopy b(*(PadCopy*)&getRaw());
    if ((b.words[1] & 8) || ((signed char)b.b1 > 30)) return 1;
    if ((b.words[1] & 4) || ((signed char)b.b1 < -30)) return 2;
    if ((b.words[1] & 2) || ((signed char)b.b0 > 30)) return 3;
    if ((b.words[1] & 1) || ((signed char)b.b0 < -30)) return 4;
    return 0;
}
extern "C" void fn_80152A60(void*, const void*, unsigned int);
extern "C" void fn_80153610(void*, void*, int, int, int, int, int);
extern "C" void* fn_800F27C8(void*, const void*, unsigned int);
extern "C" int fn_800F2AEC(Self* self) {
    switch (self->state) {
    case 0:
        if (++self->counter == 2) {
            ThreadEx* t = (ThreadEx*)self->thread;
            t->m340b = self->d4;
            void* buffer = self->buffer84;
            char* data = (char*)self->buffer88 + 8;
            t = (ThreadEx*)self->thread;
            t->m342 = 0x280;
            t->m344 = 0x1E0;
            t->m348 = 6;
            t->m34c = 0x19000;
            t->m350 = buffer;
            t->m358 = data;
            OSResumeThread((OSThread*)((char*)self->thread + 8));
            self->state = 1;
        }
        break;
    case 1: {
        gfThread* t = self->thread;
        if (((s32)*(u32*)((char*)t + 0x340) >> 24) == 2) {
            self->state = 2;
            self->counter = 0;
            if (t != 0) {
                __dt__8gfThreadFv(t, 0);
                __dl__FPv(t);
            }
            self->thread = 0;
            gfHeapManager::free(self->buffer84);
            self->buffer84 =
                fn_800F27C8(self, (char*)self->buffer88 + 8, 0x19000);
            unsigned char* p = self->buffer88;
            p[0] = (((u8*)g_GameGlobal->getGlobalRecordMenuDatap())[0x28] >> 7) & 1;
            *(u32*)(p + 4) = 0x19000;
            fn_80152A60(self->objectbc, self->buffer88, 0x19008);
            fn_80153610(self->object9c, self->objectbc, self->c8, self->cc, self->d4, 0, 0);
            void* buffer = self->buffer84;
            fn_80153610(self->object9c, self->objectbc, self->c8, self->cc, self->d4, 0, 0);
            self->objecta4 = buffer;
        }
        break;
    }
    case 2: {
        PadCopy a(*(PadCopy*)&getRaw());
        int dir = getDirection();
        if (a.words[3] != 0 || dir != 0 || ++self->counter >= 0xB4)
            return 3;
        break;
    }
    }
    return self->result;
}