#pragma switch_tables on
#pragma force_active on

#include <nt/nt_offline.h>

typedef unsigned char u8;

extern int gUnk805a03d8;
extern int lbl_805A03A8;
extern char lbl_8045726C[];

extern "C" u8 fn_800C851C();
extern "C" int fn_800C8524();
extern "C" u8 fn_800C8548();
extern "C" void netReport__FPCce(const char*, ...);
extern "C" void fn_800C8F68(const char*, ...);
extern "C" void fn_800D0AE0(void*, void*);
extern "C" void fn_80145B98(int, int);
extern "C" void fn_8014CB1C(void*, int);

struct NetworkData {
    char pad[0x33F4];
    u8 flag;
};

struct Network {
    char pad[0x30];
    NetworkData* data;
};

extern Network g_Network;

struct Flags {
    u8 rest : 7;
    u8 flag : 1;
};

struct Entry {
    u8 pad0[0x68];
    u8 states[4];
    u8 pad1[0xC];
    u8 active : 1;
    u8 flags : 7;
    u8 unk79;
    u8 pad2[2];
    unsigned int state : 5;
    unsigned int rest : 27;
    u8 pad3[0x218 - 0x80];
};

struct Parent {
    u8 pad[0x70];
    Entry entries[5];
};

inline u8 localIdx() {
    u8 index = fn_800C851C();
    if (index == 0xFF)
        index = 4;
    return index;
}

inline Entry* getLocal(void* self) {
    return &((Parent*)self)->entries[localIdx()];
}

inline Entry* getSelectedA(u8* self) {
    u8 index = fn_800C8548();
    if (index == 0xFF)
        return getLocal(self);
    Entry* entry = &((Parent*)self)->entries[index];
    if (!entry->active)
        return getLocal(self);
    return entry;
}

inline u8* getSelected(u8* self) {
    u8 index = fn_800C8548();
    if (index == 0xFF)
        return (u8*)getLocal(self);
    u8* p = self + index * 0x218;
    u8* entry = p + 0x70;
    if (!((p[0xE8] >> 7) & 1))
        return (u8*)getLocal(self);
    return entry;
}

#define SET_STATUS(value)                                                    \
    do {                                                                     \
        ntFriendInfo* info = ntFriendInfo::getInstance();                     \
        (*(u8**)info)[0x577] = (value);                                      \
        g_Network.data->flag = 1;                                            \
        netReport__FPCce(lbl_8045726C, (value));                            \
        fn_800C8F68(lbl_8045726C, (value));                                 \
        if (fn_800C8524() != 0) {                                           \
            u8 index = fn_800C8548();                                       \
            Entry* entry;                                                    \
            if (index == 0xFF)                                              \
                entry = 0;                                                   \
            else                                                             \
                entry = &((Parent*)self)->entries[index];                    \
            if (entry != 0) {                                               \
                entry->state = (value);                                     \
                u8 local = fn_800C851C();                                   \
                if (local == 0xFF)                                          \
                    local = 4;                                               \
                u8* p = base + local * 0x218;                               \
                ((Flags*)(p + 0xC6))->flag = 0;                             \
                fn_800D0AE0(self, p);                                       \
                fn_80145B98(lbl_805A03A8, 0xFE);                            \
            }                                                                \
        }                                                                    \
    } while (0)

extern "C" void fn_800CD934(void* self, u8 count) {
    u8* base = (u8*)self;

    if (gUnk805a03d8 == 4) {
        u8 selected;
        Entry* entry;
        int sub;
        u8 player;

        player = base[0x4C];
        sub = base[0x4D];
        int cond = (base[0xFCA] >> 5) & 1;

        if (cond == 0) {
            u8 index = fn_800C8548();
            if (index == 0xFF)
                entry = 0;
            else
                entry = &((Parent*)base)->entries[index];

            if (entry == 0)
                entry = getLocal(base);

            selected = entry->unk79;
            int valid;
            if (selected >= 4) {
                valid = 0;
            } else {
                Entry* current = getSelectedA(base);
                valid = current->states[selected] == 1;
            }

            u8 pick = valid ? entry->unk79 : 0xFF;
            cond = pick == localIdx();
        }

        if (cond != 0 && ((base[0x51] >> 7) & 1)) {
            player = 0;
        } else if (player == 4) {
            player = 0;
        } else if (player > 4) {
            player = 0;
        } else {
            u8* current = getSelected(base);
            int valid;
            if ((current + player)[0x68] != 1) {
                valid = 0;
            } else {
                s32 word = *(s32*)(current + 0x84 + player * 0x18 + sub * 8);
                valid = (word >> 24) == 1;
            }

            if (valid)
                player = (base + player * 0x218)[0xC5];
            else
                player = 0;
        }

        if (player == 0)
            player = 1;

        int players = player;

        if (base[0xFD6] != count) {
            base[0xFD6] = count;
            u8* info = *(u8**)ntFriendInfo::getInstance();
            if (count > 4)
                count = 4;
            info[0x578] = count;

            if (fn_800C8524() != 0) {
                switch (*(unsigned int*)(base + 0x6C)) {
                case 0:
                    if (base[0xFD6] >= 4) {
                        SET_STATUS(0x19);
                    } else if (players != 4) {
                        SET_STATUS(0x13);
                    } else {
                        SET_STATUS(0x17);
                    }
                    break;

                case 1:
                    if (players < 4) {
                        if (base[0xFD6] >= 2) {
                            SET_STATUS(0x1A);
                        } else {
                            SET_STATUS(0x14);
                        }
                    }
                    break;

                case 7:
                    if (players < 4) {
                        if (base[0xFD6] >= 4) {
                            SET_STATUS(0x0A);
                        } else {
                            SET_STATUS(0x0E);
                        }
                    }
                    break;

                case 2:
                    if (players < 4) {
                        if (base[0xFD6] >= 2) {
                            SET_STATUS(0x1B);
                        } else {
                            SET_STATUS(0x15);
                        }
                    }
                    break;

                case 3:
                case 5:
                case 6:
                    break;
                }
            }

            g_Network.data->flag = 1;
            fn_8014CB1C(ntFriendInfo::getInstance(), 1);
        }
    }
}
