#include <types.h>
#pragma force_active on

struct Entry {
    u8 kind;
    u8 status;
    u8 pad2[3];
    u8 id;
    u8 team;
    u8 pad7[0x13];
    u16 hits[4];
    u8 pad22[0x2AC - 0x22];
};

struct Self {
    u8 pad0[2];
    u8 teamMode;
    u8 pad3[0x21];
    Entry entries[4];
    u8 padEnd[0x1384 - 0x24 - 4 * 0x2AC];
    u32 time;
};

struct Rec {
    u16 a;
    u16 b;
    u8 rest[0x50];
    u32 times[1];
};

extern void* g_GameGlobal;
extern "C" Rec* fn_8004D138(void*, int);
extern "C" u8 exchangeGmCharacterKindToMuCharKind__6muMenuFiii(int);
extern "C" void fn_800548D0(Self*, int, void*);

static inline void addSat16(u16* p, u16 b) {
    int ovf = 1;
    if (*p <= 0xFFFF - b) {
        ovf = 0;
    }
    u16 r = 0xFFFF;
    if (!ovf) {
        r = *p + b;
    }
    *p = r;
}

static inline void addSat32(u32* p, u32 t) {
    int ovf = (t > 0x157529FF || *p > 0x157529FF - t);
    u32 r;
    if (ovf) {
        r = 0x157529FF;
    } else {
        r = *p + t;
    }
    *p = r;
}

extern "C" void fn_800551C8(Self* self) {
    u32 t;
    Entry* e;
    int offset;
    Entry* entries;
    int i;
    entries = self->entries;
    e = entries;
    i = 0;
    for (offset = 0; i < 4; i++, e++, offset += 2) {
        if (e->status == 0 && e->id != 0x78) {
            Rec* rec = fn_8004D138(g_GameGlobal, e->id);
            for (int j = 0; j < 4; j++) {
                Entry* o = &entries[j];
                if (i != j && o->status != 3 && !(e->status == 1 && o->status == 1)) {
                    if (self->teamMode != 1 || e->team != o->team) {
                        addSat16(&rec->a, e->hits[j]);
                    }
                    addSat16(&rec->b, ((Entry*)((char*)offset + (u32)o))->hits[0]);
                }
            }
            t = self->time / 60;
            u32* p = &rec->times[exchangeGmCharacterKindToMuCharKind__6muMenuFiii(e->kind)];
            addSat32(p, t);
            fn_800548D0(self, i, &rec->rest[0]);
        }
    }
}
