#include <types.h>

#pragma force_active on

extern const float lbl_805A4610;

struct Vec4 {
    float x, y, z, w;
    inline void set(float f) { w = f; z = f; y = f; x = f; }
};

struct Edge {
    u16 flags;
    u16 index;
};

struct Face {
    char pad[8];
    u16 start;
    u16 end;
    char pad2[4];
};

struct Entry {
    u16 index;
    u16 pad;
    u16* indices;
    int count;
    int pad2;
};

struct Object {
    char pad[0x70];
    Face* faces;
    char pad2[8];
    Edge* edges;
    char pad3[0x20];
    int enabled;
    int shift;
    Entry* entries;
};

extern "C" void fn_8030B338(
    Object* obj, int n, int value, const Face* face,
    unsigned int skip, unsigned int* bits
) {
    Vec4 zero __attribute__((aligned(16)));
    int start, end;
    int cnt;
    int i;
    int groups;
    Vec4* out;
    Edge* p;
    int enabled;

    zero.set(lbl_805A4610);
    cnt = n >> 7;
    start = face->start;
    end = face->end;
    out = (Vec4*)bits;
    for (i = 0; i <= cnt; i++) {
        *out++ = zero;
    }

    p = obj->edges + 1;
    enabled = obj->enabled;
    if (enabled != 0) {
        int k = value >> (16 - obj->shift);
        if (k > 0) {
            Entry* entry = &obj->entries[k - 1];
            int index = entry->index;
            u32 word = index >> 5;
            u32 bit = index & 31;
            u32 mask = 1 << bit;
            bits[word] ^= mask;

            u16* q = entry->indices;
            int cnt2 = entry->count;
            int last = cnt2 - 1;
            for (int j = 0; j <= last; ++j, ++q) {
                int idx = *q;
                if (idx != skip) {
                    int word = idx >> 5;
                    u32 mask = 1 << (idx & 31);
                    bits[word] ^= mask;
                }
            }

            Face* f = obj->faces + entry->index;
            int fs = f->start;
            p = obj->edges + (fs + 1);
            int fe = f->end;
            Edge* eend = obj->edges + fe;
            for (; p < eend; p++) {
                if (!(p->flags & 1)) {
                    int idx = p->index;
                    int word = idx >> 5;
                    u32 mask = 1 << (idx & 31);
                    bits[word] &= ~mask;
                }
            }
            p = obj->edges + (f->start + 1);
        }
    }
    Edge* pe = obj->edges + start;
    for (; p < pe; p++) {
        int index = p->index;
        int word = index >> 5;
        u32 mask = 1 << (index & 31);
        bits[word] ^= mask;
    }
    p++;
    Edge* pe2 = obj->edges + end;
    for (; p < pe2; p++) {
        if (!(p->flags & 1)) {
            int index = p->index;
            int word = index >> 5;
            u32 mask = 1 << (index & 31);
            bits[word] ^= mask;
        }
    }
}
