#include <gm/gm_global.h>
#pragma force_active on
struct Entry {
    int id;
    char pad04[0x10];
    u16 rank1, rank2, rank3;
    char pad1a[0xa];
    int score;
    char pad28;
    u8 mask;
    char pad2a[0x2e];
    u32 order;
    char pad5c[8];
};
struct Context {
    Entry* entries;
    char pad04[0xc];
    u32 selectedCount;
    u16 values[1000];
    u32 indices[1000];
    u32 selected[1000];
    u8 flags[1000];
    u8 states[1000];
    u32 count;
    char pad2ef8[8];
    u32 mask;
};
extern "C" void fn_800ADD1C(Context* self, u32 mode, int skip) {
    switch (mode) {
    case 0:
        for (u32 i = 0; i < self->count; i++)
            self->indices[i] = self->entries[i].id - 1;
        break;
    case 1:
        for (u32 i = 0; i < self->count; i++)
            self->indices[self->entries[i].order] = i;
        break;
    case 2:
        for (u32 i = 0; i < self->count; i++)
            self->indices[i] = self->entries[i].id - 1;
        break;
    case 3:
        for (u32 i = 0; i < self->count; i++)
            self->indices[i] = self->entries[i].id - 1;
        u32 b, a;
        for (u32 i = 0; i < self->count - 1; i++) {
            for (u32 j = self->count - 1; j > i; j--) {
                a = self->indices[j-1];
                b = self->indices[j];
                if (self->entries[b].score > self->entries[a].score) {
                    self->indices[j] = a;
                    self->indices[j-1] = b;
                }
            }
        }
        break;
    case 4:
        for (u32 i = 0; i < self->count; i++)
            self->indices[i] = self->entries[i].id - 1;
        u32 d, c;
        for (u32 i = 0; i < self->count - 1; i++) {
            for (u32 j = self->count - 1; j > i; j--) {
                c = self->indices[j-1];
                d = self->indices[j];
                if (self->values[d] > self->values[c]) {
                    self->indices[j] = c;
                    self->indices[j-1] = d;
                }
            }
        }
        break;
    case 5:
        u32 value;
        u8* ptr;
        u32 previous;
        for (u32 i = 0; i < self->count; i++)
            self->indices[i] = self->entries[i].id - 1;
        for (u32 i = 0; i < self->count - 1; i++) {
            for (u32 j = self->count - 1; j > i; j--) {
                value = self->indices[j];
                ptr = (u8*)self + value;
                if ((ptr[0x2724] == 1 && self->flags[previous = self->indices[j-1]] == 0) ||
                    (ptr[0x2b0c] == 1 && self->states[previous = self->indices[j-1]] == 0)) {
                    self->indices[j] = previous;
                    self->indices[j-1] = value;
                }
            }
        }
        break;
    case 6:
        if (((u8*)g_GameGlobal->getGlobalRecordMenuDatap())[0x1a] == 0) {
            for (u32 i = 0; i < self->count; i++)
                self->indices[self->entries[i].rank1 - 1] = i;
        } else {
            for (u32 i = 0; i < self->count; i++)
                self->indices[self->entries[i].rank2 - 1] = i;
        }
        break;
    case 7:
        u32 second, first;
        for (u32 i = 0; i < self->count; i++)
            self->indices[i] = self->entries[i].id - 1;
        for (u32 i = 0; i < self->count - 1; i++) {
            for (u32 j = self->count - 1; j > i; j--) {
                first = self->indices[j-1];
                second = self->indices[j];
                if (self->entries[second].rank3 < self->entries[first].rank3) {
                    self->indices[j] = first;
                    self->indices[j-1] = second;
                }
            }
        }
        break;
    }
    if (skip == 0) {
        u32* src = (u32*)self;
        u32* dst = (u32*)self;
        u32 index;
        u32 n = 0;
        for (u32 i = 0; i < self->count; ++src, ++i) {
            index = src[0x7e4 / 4];
            if (self->states[index] == 1 && (self->mask & self->entries[index].mask)) {
                dst[0x7e4 / 4] = index;
                ++dst;
                ++n;
            }
        }
        self->selectedCount = n;
    } else {
        self->selectedCount = self->count;
    }
}