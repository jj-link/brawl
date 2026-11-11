#pragma force_active on
#include <types.h>
#include <mu/wifi/mu_wifi_interface.h>

extern "C" int fn_800C8524(void);
extern "C" u8 fn_800C8548(void);
extern "C" u8 fn_800C851C(void);
extern "C" int fn_8014592C(int);
extern "C" void fn_800D0AE0(void*, void*);
extern "C" void fn_80145B98(int, int);
extern "C" void fn_8014BF30(int, int, int);

extern int lbl_805A03A8;
extern int lbl_805A0434;
extern char lbl_804579AC[];
extern char lbl_804579E8[];

struct Entry {
    u8 pad0[0x56];
    u8 localFlags : 7;
    u8 lowFlag : 1;
    u8 padBeforeActive[0x78 - 0x57];
    u8 active : 1;
    u8 flags : 7;
    u8 pad1[0x218 - 0x79];
};

struct Parent {
    u8 pad[0x70];
    Entry entries[5];
};

inline u8* getInitial(u8* self) {
    u8 idx = fn_800C8548();
    if (idx == 0xFF)
        return 0;
    return (u8*)&((Parent*)self)->entries[idx];
}

inline u8* getSelectedForState(u8* self) {
    u8 idx = fn_800C8548();
    if (idx == 0xFF) {
        u8 local = fn_800C851C();
        if (local == 0xFF) local = 4;
        return self + local * 0x218 + 0x70;
    }
    u8* p = (u8*)((unsigned int)self + idx * 0x218 + 0x70);
    if (!((Entry*)p)->active) {
        u8 local = fn_800C851C();
        if (local == 0xFF) local = 4;
        return self + local * 0x218 + 0x70;
    }
    return p;
}

inline int countPlayers(u8* self) {
    u8 idx = fn_800C8548();
    s8* p;
    if (idx == 0xFF)
        p = 0;
    else
        p = (s8*)(self + idx * 0x218 + 0x70);
    int count;
    if (p == 0) {
        count = 1;
    } else {
        count = 0;
        if (p[0x68] == 1) count = 1;
        if (p[0x69] == 1) count++;
        if (p[0x6A] == 1) count++;
        if (p[0x6B] == 1) count++;
    }
    return count;
}

inline bool readyStatus(u8* self) {
    u8* p = getInitial(self);
    if (p == 0)
        return 0;
    u8 flags = p[0x78];
    if ((flags >> 7) & 1)
        return (flags >> 6) & 1;
    return 0;
}

extern "C" int fn_800CAA60(u8* self) {
    u8* initial;
    u8 slot;
    u8* owner;
    int sub;
    u8 player;
    u8* record;
    u8* flag;
    unsigned int i;
    int matches;
    int row;

    if (fn_800C8524() != 0) {
        fn_800C8548();
        initial = getInitial(self);
        u8 idx;

        if ((self[0xFC9] >> 3) & 1) {
            if (initial[0x6C] != 0xFF)
                return 0;
            i = 0;
            do {
                u8* p = getSelectedForState(self);
                if ((u32)(p[(u8)i + 0x68] - 2) <= 1)
                    return 0;
                i++;
            } while (i < 4);
        }

        u8 countIdx = fn_800C8548();
        s8* countEntry;
        if (countIdx == 0xFF)
            countEntry = 0;
        else
            countEntry = (s8*)(self + countIdx * 0x218 + 0x70);
        int count;
        if (countEntry == 0) {
            count = 1;
        } else {
            count = 0;
            if (countEntry[0x68] == 1) count = 1;
            if (countEntry[0x69] == 1) count++;
            if (countEntry[0x6A] == 1) count++;
            if (countEntry[0x6B] == 1) count++;
        }
        if (count < 2)
            return 0;

        matches = 0;
        row = 0;
        record = self;
        flag = self + 0x51;
        do {
            player = record[0x4C];
            sub = record[0x4D];
            int cond = (self[0xFCA] >> 5) & 1;
            if (!cond) {
                idx = fn_800C8548();
                if (idx == 0xFF)
                    owner = 0;
                else
                    owner = (u8*)((unsigned int)self + idx * 0x218 + 0x70);
                if (owner == 0) {
                    u8 local = fn_800C851C();
                    if (local == 0xFF) local = 4;
                    owner = (u8*)((unsigned int)self + local * 0x218 + 0x70);
                }
                slot = owner[0x79];
                int valid;
                if (slot >= 4) {
                    valid = 0;
                } else {
                    u8* target;
                    idx = fn_800C8548();
                    if (idx == 0xFF) {
                        u8 local = fn_800C851C();
                        if (local == 0xFF) local = 4;
                        target = (u8*)((unsigned int)self + local * 0x218 + 0x70);
                    } else {
                        target = (u8*)((unsigned int)self + idx * 0x218 + 0x70);
                        if (!((target[0x78] >> 7) & 1)) {
                            u8 local = fn_800C851C();
                            if (local == 0xFF) local = 4;
                            target = (u8*)((unsigned int)self + local * 0x218 + 0x70);
                        }
                    }
                    valid = (target[slot + 0x68] == 1);
                }
                u8 pick = valid ? owner[0x79] : 0xFF;
                u8 local = fn_800C851C();
                if (local == 0xFF) local = 4;
                cond = (pick == local);
            }

            u8 value;
            if (cond && ((flag[0] >> 7) & 1)) {
                value = 0;
            } else if (player == 4) {
                value = 0;
            } else if (player > 4) {
                value = 0;
            } else {
                u8* target;
                idx = fn_800C8548();
                if (idx == 0xFF) {
                    u8 local = fn_800C851C();
                    if (local == 0xFF) local = 4;
                    target = (u8*)((unsigned int)self + local * 0x218 + 0x70);
                } else {
                    u8* base = self + idx * 0x218;
                    target = base + 0x70;
                    if (!((base[0xE8] >> 7) & 1)) {
                        u8 local = fn_800C851C();
                        if (local == 0xFF) local = 4;
                        target = (u8*)((unsigned int)self + local * 0x218 + 0x70);
                    }
                }
                int valid;
                if (target[player + 0x68] != 1) {
                    valid = 0;
                } else {
                    int word = *(int*)(target + 0x84 + player * 0x18 + sub * 8);
                    valid = ((word >> 24) == 1);
                }
                if (valid)
                    value = self[player * 0x218 + 0xC5];
                else
                    value = 0;
            }
            if ((int)value == 3)
                matches++;
            row++;
            record += 8;
            flag += 8;
        } while (row < 4);

        if (matches != self[0xFD5])
            return 0;
        int mode = *(int*)(self + 0x6C);
        if (mode == 5 && matches < 4 && *(u16*)(self + 0xFDA) != 0)
            return 0;
        if (mode == 7 && matches < 4)
            return 0;
        if (!fn_8014592C(lbl_805A03A8))
            return 0;

        if (!((initial[0x78] >> 6) & 1)) {
            initial[0x78] |= 0x40;
            idx = fn_800C851C();
            if (idx == 0xFF) idx = 4;
            u8* q = self + idx * 0x218;
            ((Entry*)(q + 0x70))->lowFlag = 0;
            fn_800D0AE0(self, q);
            fn_80145B98(lbl_805A03A8, 0xFE);
            netReport(lbl_804579AC, matches);
            fn_8014BF30(lbl_805A0434, 1, 0x3C);
        }
        return 1;
    }

    if ((*(int*)(self + 0xFCC) >> 24) != 4)
        return 0;
    int value = readyStatus(self);
    if (!((self[0xFC9] >> 5) & 1) && value != 0) {
        self[0xFC9] |= 0x20;
        netReport(lbl_804579E8);
        fn_8014BF30(lbl_805A0434, 1, 0x3C);
    }
    return value;
}
