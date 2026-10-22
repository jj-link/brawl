#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_80281AE8(const char*, const char*);
}

struct Inner {
    u8 pad[0x14];
    s32 m_count;
};

struct Entries {
    u8 pad0[0xc];
    Inner* m_inner;
    char* m_entries;
};

extern "C" s32 fn_80331408(Entries* self, const char* name) {
    s32 idx = 0;
    s32 off = 0;
    for (s32 i = 0; i < self->m_inner->m_count; i++) {
        if (fn_80281AE8(self->m_entries + off, name) == 0) {
            return i;
        }
        off += 0x30;
    }
    return -1;
}
