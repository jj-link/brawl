#include <gm/gm_global.h>
#pragma force_active on
extern "C" u8 fn_8004EAC8(u8**);

struct Entry {
    u8 pad0[0x29];
    u8 mask;
    u8 pad2A[2];
    int kind;
    u8 pad30[0x34];
};

struct Context {
    Entry* entries;
    u8 pad4[8];
    u32 selectedCount;
    u32 count;
    u8 pad14[0x7D0];
    int indices[1000];
    u32 selected[1000];
    u8 flags[1000];
    u8 states[1000];
    u8 pad2EF4[0xC];
    u32 mask;
};

extern "C" u32 fn_800AE200(Context* self, int mode, int skip) {
    u32 n = 0;
    switch (mode) {
    case 0: {
        int* src = (int*)self;
        u32* dst = (u32*)self;
        for (u32 i = 0; i < self->count; ++src, ++i) {
            int k = self->entries[src[0x7E4 / 4]].kind;
            if (k == 0 || (k >= 6 && k <= 0x17) ||
                (k >= 0x1C && k <= 0x1D) ||
                (k >= 0x2F && k <= 0x45 && k != 0x35 && k != 0x37)) {
                dst[0x1784 / 4] = i;
                ++dst;
                ++n;
            }
        }
        break;
    }
    case 1: {
        int* src = (int*)self;
        u32* dst = (u32*)self;
        for (u32 i = 0; i < self->count; ++src, ++i) {
            int k = self->entries[src[0x7E4 / 4]].kind;
            if (k == 1 || (k >= 0x18 && k <= 0x1B) || k == 0x35 || k == 0x37) {
                dst[0x1784 / 4] = i;
                ++dst;
                ++n;
            }
        }
        break;
    }
    case 2: {
        int* src = (int*)self;
        u32* dst = (u32*)self;
        for (u32 i = 0; i < self->count; ++src, ++i) {
            int k = self->entries[src[0x7E4 / 4]].kind;
            if (!(k == 0 || (k >= 6 && k <= 0x17) ||
                (k >= 0x1C && k <= 0x1D) ||
                (k >= 0x2F && k <= 0x45 && k != 0x35 && k != 0x37)) &&
                !(k == 1 || (k >= 0x18 && k <= 0x1B) || k == 0x35 || k == 0x37)) {
                dst[0x1784 / 4] = i;
                ++dst;
                ++n;
            }
        }
        break;
    }
    case 3: {
        int* src = (int*)self;
        u32* dst = (u32*)self;
        for (u32 i = 0; i < self->count; ++src, ++i) {
            if (self->flags[src[0x7E4 / 4]]) {
                dst[0x1784 / 4] = i;
                ++dst;
                ++n;
            }
        }
        break;
    }
    }
    if (skip == 0) {
        if (fn_8004EAC8((u8**)g_GameGlobal) == 0)
            self->mask = 1;
        else
            self->mask = 2;
        u32* src = (u32*)self;
        u32* dst = (u32*)self;
        for (u32 i = 0, end = n; i < end; ++src, ++i) {
            u32 selected = src[0x1784 / 4];
            int index = self->indices[selected];
            if (self->states[index] == 1 && (self->mask & self->entries[index].mask)) {
                dst[0x1784 / 4] = selected;
                ++dst;
            } else {
                --n;
            }
        }
    }
    self->selectedCount = n;
    return n;
}
