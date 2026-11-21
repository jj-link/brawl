#include <types.h>
#include <gf/gf_heap_manager.h>
#include <cstring>
#pragma force_active on

struct Elem {
    char pad0[0x88];
    void* ptr;
    char pad1[0x14];
};

struct Arr {
    Elem* data;
    u16 cap;
    u16 count;
};

struct Obj {
    char pad0[0x48];
    u16 unk48;
    char pad1[0x7C - 0x4A];
    char unk7C[8];
    char unk84[8];
    void* unk8C;
    u16 unk90;
    char pad2[0x94 - 0x92];
    u8 unk94;
    char pad3[0x9C - 0x95];
    Arr a9C;
    u8 unkA4;
    char pad4[0xAC - 0xA5];
    Arr aAC;
    s32 unkB4;
    void clearSecond() {
        if (aAC.data != 0) {
            for (u16 q = 0; q < aAC.cap; q++) {
                void* p = aAC.data[q].ptr;
                if (p != 0) {
                    gfHeapManager::free(p);
                }
            }
            gfHeapManager::free(aAC.data);
            aAC.data = 0;
        }
        aAC.cap = 0;
        aAC.count = 0;
    }
    void clearFirst() {
        if (a9C.data != 0) {
            for (u16 q = 0; q < a9C.cap; q++) {
                void* p = a9C.data[q].ptr;
                if (p != 0) {
                    gfHeapManager::free(p);
                }
            }
            gfHeapManager::free(a9C.data);
            a9C.data = 0;
        }
        a9C.cap = 0;
        a9C.count = 0;
    }
};

extern "C" {
long long OSGetTime(void);
void fn_800340AC(Obj*, void*);
void fn_8003478C(Obj*, void*);
u32 fn_80034998(Obj*, Arr*, void*, u16);
void fn_80035BEC(Obj*);
}

extern "C" void fn_80033B48(Obj* self) {
    if (self->unkB4 != 3) {
        return;
    }
    u32 r4 = 0;
    if (self->unk94 != 0 || self->unkA4 != 0) {
        r4 = 1;
    }
    if (r4 == 0 && self->a9C.count == 0 && self->aAC.count == 0) {
        return;
    }

    OSGetTime();
    fn_80035BEC(self);
    s32 r30 = self->unk48;
    if (self->unk94 != 0) {
        fn_800340AC(self, &self->unk94);
        fn_80035BEC(self);
    }

    Arr* b;
    Arr* a = &self->a9C;
    if (self->a9C.count != 0) {
        u32 r3 = fn_80034998(self, a, self->unk7C, r30);
        for (u16 i = 0; i < (u16)r3; i++) {
            void* p = a->data[i].ptr;
            if (p != 0) {
                gfHeapManager::free(p);
                a->data[i].ptr = 0;
            }
        }
        Elem* dst = a->data;
        Elem* src = a->data + (u16)r3;
        u16 n = a->count - r3;
        for (u16 j = 0; j < n; j++) {
            Elem* d = dst;
            Elem* s = src;
            dst++;
            src++;
            memcpy(d, s, 0xA0);
        }
        for (u16 k = n; k < a->cap; k++) {
            a->data[k].ptr = 0;
        }
        a->count = n;
        r30 = r30 - r3;
        if (n == 0 && self->unk94 == 0) {
            self->clearFirst();
        }
    }

    if ((u16)r30 != 0) {
        if (self->unkA4 != 0) {
            fn_8003478C(self, &self->unkA4);
            fn_80035BEC(self);
        }
        b = &self->aAC;
        if (self->aAC.count != 0) {
            u32 r3 = fn_80034998(self, b, self->unk84, r30);
            for (u16 i = 0; i < (u16)r3; i++) {
                void* p = b->data[i].ptr;
                if (p != 0) {
                    gfHeapManager::free(p);
                }
            }
            Elem* dst = b->data;
            Elem* src = b->data + (u16)r3;
            u16 n = b->count - r3;
            for (u16 j = 0; j < n; j++) {
                Elem* d = dst;
                Elem* s = src;
                dst++;
                src++;
                memcpy(d, s, 0xA0);
            }
            for (u16 k = n; k < b->cap; k++) {
                b->data[k].ptr = 0;
            }
            b->count = n;
            if (n == 0 && self->unkA4 == 0) {
                self->clearSecond();
                if (&self->unk8C != 0) {
                    if (self->unk8C != 0) {
                        gfHeapManager::free(self->unk8C);
                        self->unk8C = 0;
                    }
                    self->unk90 = 0;
                }
            }
        }
    }

    fn_80035BEC(self);
    OSGetTime();
}