#include <types.h>
#include <ut/ut_relocate.h>
#pragma force_active on

struct GG {
    u8 padding[0x24];
    u8* base;
};

extern GG* g_GameGlobal;
extern char lbl_80454488[];

struct Entry8 {
    u32 a;
    u16 b;
    u8 id;
    u8 c;
};

struct InRec {
    u8 id;
    u32 a;
    u8 c;
    u16 b;
};

struct Self {
    Entry8* entries;
    u32 count[45];
    u32 start[45];
    u32 total;
    u8 padding[0x14C8 - 0x170];
    u8* buf;
    u32 size;
};

extern "C" void fn_80078768(Self* self) {
    {
        self->entries = (Entry8*)(g_GameGlobal->base + 0x358C);
        utRelocate reloc(self->buf, self->size);
        InRec* rec = (InRec*)reloc.getPublicAddress(lbl_80454488);
        u32 n = 0;
        while (rec->id != 0xFF) {
            self->entries[n].id = rec->id;
            self->entries[n].a = rec->a;
            self->entries[n].c = rec->c;
            self->entries[n].b = rec->b;
            rec++;
            n++;
        }
        self->entries[n].id = 0xFF;
    }
    u32 cur = self->entries[0].id;
    u32 g = 0;
    u32 i;
    for (i = 0; i < 45; i++) {
        self->count[i] = 0;
        self->start[i] = 0;
    }
    for (i = 0; self->entries[i].id != 0xFF; i++) {
        if (cur != self->entries[i].id) {
            self->start[g + 1] = i;
            g++;
            cur = g;
        }
        self->count[g]++;
        self->total++;
    }
}
