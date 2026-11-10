#include <ec/ec_trace_mgr.h>
#include <types.h>
#pragma force_active on

struct Tbl1 { u32 v[134]; };
struct Tbl2 { const char* v[134]; };

struct Entry {
    u32 active;
    u8 pad04[4];
    void* p8;
    u8 pad0C[4];
    u32 id;
    u8 pad14[4];
};

struct Owner {
    u8 pad00[0x58];
    Entry* entries;
    u32 count;
    u8 pad60[0x21];
    u8 kind;
    u8 pad82[2];
    u32 slot[4];
};

static inline Entry* findEntry(Owner* self, u32 id) {
    for (u32 i = 0; i < self->count; i++) {
        if (self->entries[i].active && self->entries[i].id == id)
            return &self->entries[i];
    }
    return 0;
}

extern "C" {
extern const Tbl1 lbl_80407198;
extern const Tbl2 lbl_804073B0;
extern void* g_GameGlobal;
u32 fn_8004E958(void* p);
void* fn_8018D3F0(void* a, const char* b);

void fn_80061160(Owner* self, u32 a1, s32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u8 a7, f32 f) {
    Tbl1 ids = lbl_80407198;
    Tbl2 names = lbl_804073B0;

    if (a2 >= 1) {
        u32 idx = a2 - 1;
        if (idx < 0x86) {
            Entry* found = findEntry(self, ids.v[idx]);
            if (found) {
                u32 sp10 = (u32)fn_8018D3F0(found->p8, names.v[idx]);
                u32* pSp10 = &sp10;
                if (sp10 != 0) {
                    u32 flag = 0;
                    if (a2 >= 0x55 && a2 <= 0x59) {
                        flag = 1;
                    } else if (a2 >= 0x5F && a2 <= 0x63) {
                        flag = 1;
                    } else if (a2 >= 0x69 && a2 <= 0x6D) {
                        flag = 1;
                    } else if (a2 >= 0x73 && a2 <= 0x77) {
                        flag = 1;
                    } else {
                        switch (a2) {
                        case 0xA:
                        case 0xB:
                        case 0x10:
                        case 0x1E:
                        case 0x1F:
                        case 0x20:
                        case 0x22:
                        case 0x23:
                        case 0x25:
                        case 0x28:
                        case 0x2B:
                        case 0x2E:
                        case 0x31:
                        case 0x34:
                        case 0x37:
                        case 0x3A:
                        case 0x3D:
                        case 0x40:
                        case 0x43:
                        case 0x46:
                        case 0x49:
                        case 0x4C:
                        case 0x4F:
                        case 0x7B:
                        case 0x82:
                            flag = 1;
                            break;
                        }
                    }
                    ((ecTraceMgr*)((u8*)self + 0x98))->start(a1, (u32)pSp10, a3, a4, a5, self->slot[self->kind], a6, a7, flag, f);
                    return;
                }
            }
        }
    }
    fn_8004E958(g_GameGlobal);
    ((ecTraceMgr*)((u8*)self + 0x98))->start(a1, a3, a4, a5, self->slot[self->kind], a6, a7, 0, f);
}
}
