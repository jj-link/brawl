#pragma force_active on

typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;
typedef signed short s16;

struct SelectedEntry {
    u8 pad[0x78];
    u8 active : 1;
    u8 flags : 7;
    u8 rest[0x218 - 0x79];
};

struct ParentView {
    u8 pad[0x70];
    SelectedEntry entries[5];
};

struct NameSlot {
    u8 name[0x218];
};

struct LowBitRecord {
    u8 pad[0xC6];
    u8 high : 7;
    u8 low : 1;
};

extern "C" u8 fn_800C851C();
extern "C" u8 fn_800C8548();
extern "C" void fn_800D0AE0(void*, void*);
extern "C" void fn_80145B98(int, int);
extern int lbl_805A03A8;
extern int g_NtAIDBitmap;
extern "C" void netReport__FPCce(const char*, ...);
extern "C" void* memset(void*, int, u32);
extern char lbl_80458808[];

extern "C" s32 fn_800D4EF0(void* self, s16* out1, u8* out2, s32* out3) {
    u8* base = (u8*)self;

    if (!((base[0xFC9] >> 3) & 1))
        return 0;

    u8 selected = fn_800C8548();
    u8* slot;
    if (selected == 0xFF)
        slot = 0;
    else
        slot = (u8*)&((ParentView*)self)->entries[selected];

    if (slot == 0)
        return 0;

    u8 local = fn_800C851C();
    if (local == 0xFF)
        local = 4;
    u8* le = base + local * 0x218;

    if (*(s32*)(le + 0xA8) >> 24 != 1)
        return 0;

    u8 aid = slot[0x6C];
    u8 v1 = slot[0x6D];
    u8 v2 = slot[0x6E];

    if (aid == 0xFF) {
        if (*(s32*)(le + 0xCC) != 0) {
            *(s32*)(le + 0xCC) = 0;
            le[0xD0] = 0xFF;
            le[0xD1] = 0;
            le[0xD2] = 0;

            u8 idx = fn_800C851C();
            if (idx == 0xFF)
                idx = 4;
            u8* p1 = base + idx * 0x218;
            ((LowBitRecord*)p1)->low = 0;

            fn_800D0AE0(self, p1);
            fn_80145B98(lbl_805A03A8, 0xFE);
        }
        return 0;
    }

    u8 sel2 = fn_800C8548();
    SelectedEntry* target;
    if (sel2 == 0xFF) {
        u8 loc = fn_800C851C();
        if (loc == 0xFF)
            loc = 4;
        target = (SelectedEntry*)(base + loc * 0x218 + 0x70);
    } else {
        target = &((ParentView*)self)->entries[sel2];
        if (!target->active) {
            u8 loc = fn_800C851C();
            if (loc == 0xFF)
                loc = 4;
            target = (SelectedEntry*)(base + loc * 0x218 + 0x70);
        }
    }

    if (((u8*)target + aid)[0x68] == 0)
        return 0;

    u8 loc2 = fn_800C851C();
    if (loc2 == 0xFF)
        loc2 = 4;

    if (aid == loc2) {
        u8 loc3 = fn_800C851C();
        if (loc3 == 0xFF)
            loc3 = 4;
        u8* p2 = base + loc3 * 0x218;
        *(s32*)(p2 + 0xCC) = 1;
        p2[0xD0] = aid;
        p2[0xD1] = v1;
        p2[0xD2] = v2;
        return 0;
    }

    if (le[0xD0] == aid && le[0xD1] == v1 && le[0xD2] == v2 &&
        *(s32*)(le + 0xCC) != 0)
        return 0;

    le[0xD0] = aid;
    le[0xD1] = v1;
    le[0xD2] = v2;
    *(s32*)(le + 0xCC) = 0;

    u8 idx2 = fn_800C851C();
    if (idx2 == 0xFF)
        idx2 = 4;
    u8* p3 = base + idx2 * 0x218;
    ((LowBitRecord*)p3)->low = 0;

    fn_800D0AE0(self, p3);
    fn_80145B98(lbl_805A03A8, 0xFE);

    if (out2)
        *out2 = aid;
    if (out3)
        *out3 = v1;

    if (aid != 4 &&
        (!(g_NtAIDBitmap & (1 << aid)) || !((base[0xFC9] >> 7) & 1))) {
        *out1 = 0;
    } else {
        int i = 5;
        u8* dst = (u8*)out1;
        u8* src = ((NameSlot*)(base + 0x250))[aid].name;
        memset(out1, 0, 0xC);

        while (--i >= 0) {
            int c = (dst[0] = src[0]) | (dst[1] = src[1]);
            src += 2;
            dst += 2;
            if (c == 0)
                break;
        }

        netReport__FPCce(lbl_80458808, aid);
    }

    if (*(unsigned short*)out1 == 0)
        return 0;
    return 1;
}
