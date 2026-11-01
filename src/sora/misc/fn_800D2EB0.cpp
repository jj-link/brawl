#pragma force_active on

typedef unsigned char u8;
typedef signed char s8;

struct EntryFlag {
    u8 pad0[0x78];
    u8 active : 1;
    u8 pad1[0x218 - 0x79];
};

struct ParentView {
    u8 pad[0x70];
    EntryFlag entries[5];
};

extern "C" u8 fn_800C851C();
extern "C" u8 fn_800C8548();

extern "C" int fn_800D2EB0(void* self, int slot) {
    u8 local = fn_800C851C();
    if (local == 0xFF)
        local = 4;
    if (local == 4)
        return 0;

    u8 selected = fn_800C8548();
    u8* entry;
    if (selected == 0xFF) {
        entry = 0;
    } else {
        entry = (u8*)self + selected * 0x218 + 0x70;
    }
    if (entry == 0)
        return 0;
    if (!((entry[0x78] >> 3) & 1))
        return 0;

    u8 player = *((u8*)self + slot * 8 + 0x4C);
    if (player == 0xFF)
        return 0;

    u8 local2 = fn_800C851C();
    if (local2 == 0xFF)
        local2 = 4;
    if (player == local2)
        return 0;

    int valid;
    if (player >= 4) {
        valid = 0;
    } else {
        u8 selected2 = fn_800C8548();
        u8* target;
        if (selected2 == 0xFF) {
            u8 local3 = fn_800C851C();
            if (local3 == 0xFF)
                local3 = 4;
            target = (u8*)self + local3 * 0x218 + 0x70;
        } else {
            target = (u8*)&((ParentView*)self)->entries[selected2];
            target += 0x70 - 0x70;
            u8 active = ((EntryFlag*)target)->active;
            if (active == 0) {
                u8 local4 = fn_800C851C();
                if (local4 == 0xFF)
                    local4 = 4;
                target = (u8*)self + local4 * 0x218 + 0x70;
            }
        }
        valid = !(*((target + player) + 0x68) - 1);
    }

    if (!valid)
        return 0;

    u8* p = (u8*)self + player * 0x218;
    if ((s8)p[0x281] >= 0)
        return 0;

    u8 local5 = fn_800C851C();
    if (local5 == 0xFF)
        local5 = 4;

    u8 flags = p[0xC8];
    if (((flags & 0xF0) >> 4) & (1 << local5))
        return 1;
    return 0;
}
