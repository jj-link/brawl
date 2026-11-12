#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

extern "C" u8 fn_800C8548();
extern "C" u8 fn_800C851C();
extern "C" void netReport__FPCce(const char*, ...);
extern char lbl_80457158[];

struct Slot {
    u8 player;
    u8 sub;
    u8 padding[2];
    signed int state : 8;
    unsigned int reserved : 24;
};

struct FlagByte {
    u8 flag : 1;
    u8 rest : 7;
};

struct Entry {
    u8 data[0x68];
    u8 states[4];
    u8 padding[0xC];
    u8 active : 1;
    u8 flags : 7;
    u8 remaining[0x218 - 0x79];
};

struct Parent {
    u8 padding[0x70];
    Entry entries[5];
};

inline u8 localIdx() {
    u8 l = fn_800C851C();
    if (l == 0xFF)
        l = 4;
    return l;
}

inline u8* localEntry(u8* self) {
    return (u8*)&((Parent*)self)->entries[localIdx()];
}

inline Entry* selectedEntry(u8* self) {
    u8 idx = fn_800C8548();
    if (idx == 0xFF)
        return (Entry*)localEntry(self);
    Entry* entry = (Entry*)((unsigned int)self + idx * 0x218 + 0x70);
    if (!entry->active)
        return (Entry*)localEntry(self);
    return entry;
}

inline void markPlayer(u8* p, int value) {
    if (p[0xC5] == 0)
        p[0xC5] = value;
}

inline int perform(int sub, void* arg0, unsigned int player) {
    int i;
    Slot* slot;
    u8 pi;
    u8* e;
    char* text = lbl_80457158;
    u8* base = (u8*)arg0;
    slot = (Slot*)(base + 0x4C);

    for (i = 0; i < 4; ++i, ++slot) {
        if (slot->player == player && slot->sub == sub &&
            slot->state == 1) {
            netReport__FPCce(text + 0x11CC, i, player, sub);
            return 1;
        }
    }

    slot = (Slot*)(base + 0x4C);
    for (i = 0; i < 4; ++i, ++slot) {
        if (slot->player == player && slot->sub == sub &&
            slot->state == 3) {
            netReport__FPCce(text + 0x120C, i, player, sub);
            slot->state = 1;
            if (sub == 0) {
                u16 v = *(u16*)(base + 0x1050);
                *(u16*)(base + 0xFDA) = v * 0x3C;
                netReport__FPCce(text + 0x1050, v);
            }
            return 1;
        }
    }

    slot = (Slot*)(base + 0x4C);
    for (i = 0; i < 4; ++i, ++slot) {
        if (slot->player == 0xFF) {
            netReport__FPCce(text + 0x1254, i, player, sub);
            slot->player = player;
            slot->sub = sub;
            slot->state = 1;
            ((FlagByte*)((u8*)slot + 5))->flag = 0;
            if (sub == 0) {
                markPlayer(base + player * 0x218, 1);
                u16 v = *(u16*)(base + 0x1050);
                *(u16*)(base + 0xFDA) = v * 0x3C;
                netReport__FPCce(text + 0x1050, v);
            }
            return 1;
        }
    }

    int do4 = (base[0xFCA] >> 5) & 1;
    if (do4 == 0) {
        u8 idx = fn_800C8548();
        if (idx == 0xFF)
            e = 0;
        else
            e = (u8*)&((Parent*)base)->entries[idx];
        if (e == 0)
            e = localEntry(base);
        pi = e[0x79];
        int m;
        if (pi >= 4) {
            m = 0;
        } else {
            Entry* selected = selectedEntry(base);
            m = selected->states[pi] == 1;
        }
        u8 target = m ? e[0x79] : 0xFF;
        do4 = target == localIdx();
    }

    if (do4) {
        slot = (Slot*)(base + 0x4C);
        for (i = 0; i < 4; ++i, ++slot) {
            u8 loc = localIdx();
            if (slot->player == loc && ((FlagByte*)((u8*)slot + 5))->flag) {
                netReport__FPCce(text + 0x129C, i, player, sub);
                slot->player = player;
                slot->sub = sub;
                slot->state = 1;
                ((FlagByte*)((u8*)slot + 5))->flag = 0;
                if (sub == 0) {
                    markPlayer(base + player * 0x218, 1);
                    u16 v = *(u16*)(base + 0x1050);
                    *(u16*)(base + 0xFDA) = v * 0x3C;
                    netReport__FPCce(text + 0x1050, v);
                }
                return 1;
            }
        }
    }

    netReport__FPCce(text + 0x12EC, player, sub);
    return 0;
}

extern "C" int fn_800D051C(void* arg0, short arg1, int arg2) {
    return perform(arg2, arg0, arg1);
}
