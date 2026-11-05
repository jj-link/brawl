#pragma force_active on

typedef unsigned char u8;
typedef signed int s32;

extern "C" u8 fn_800C8548();
extern "C" u8 fn_800C851C();

struct Entry {
    u8 pad0[0x68];
    u8 states[4];
    u8 pad1[0xC];
    u8 active : 1;
    u8 flags : 7;
    u8 unk79;
    u8 pad2[0x218 - 0x7A];

    bool isActive() const { return active != 0; }
};

struct Parent {
    u8 pad[0x70];
    Entry entries[5];
};

struct EntryView {
    u8 pad[0x70];
    u8 data[0x1A8];

    u8* getData() { return data; }
};

inline u8 localIdx() {
    u8 l = fn_800C851C();
    if (l == 0xFF)
        l = 4;
    return l;
}

inline Entry* getLocal(void* self) {
    return (Entry*)((unsigned int)self + localIdx() * 0x218 + 0x70);
}

inline u8* getSelectedOrNull(u8* self) {
    unsigned int idx = fn_800C8548();
    if (idx == 0xFF)
        return 0;
    return (u8*)((unsigned int)self + idx * 0x218 + 0x70);
}

inline Entry* getSelectedA(u8* self) {
    u8 index = fn_800C8548();
    if (index == 0xFF)
        return getLocal(self);

    Entry* entry = (Entry*)((unsigned int)self + index * 0x218 + 0x70);
    u8 active = entry->active;
    if (active == 0)
        return getLocal(self);
    return entry;
}

inline u8* getSelected(u8* self) {
    u8 idx = fn_800C8548();
    if (idx == 0xFF)
        return (u8*)getLocal(self);

    u8* p = self + idx * 0x218;
    u8* entry = p + 0x70;
    if (!((p[0xE8] >> 7) & 1))
        return (u8*)getLocal(self);
    return entry;
}

extern "C" int fn_800CA18C(void* self) {
    u8 r31;
    u8* e;
    int sub;
    u8 player;
    u8* slot;
    u8* flag;
    int i;
    int count;
    u8* base = (u8*)self;

    flag = base + 0x51;
    slot = base;
    count = 0;
    i = 0;

    do {
        int isLocal;
        if (i < 0 || i >= 4) {
            isLocal = 0;
        } else {
            u8 idx = localIdx();
            isLocal = 0;
            if (slot[0x4C] == idx && !((*flag >> 7) & 1))
                isLocal = 1;
        }

        if (isLocal) {
            if (!((*flag >> 7) & 1))
                count++;
        } else {
            player = slot[0x4C];
            sub = slot[0x4D];
            int cond = (base[0xFCA] >> 5) & 1;

            if (cond == 0) {
                e = getSelectedOrNull(base);

                if (e == 0)
                    e = (u8*)getLocal(base);

                r31 = e[0x79];
                int v;
                if (r31 >= 4) {
                    v = 0;
                } else {
                    Entry* t = getSelectedA(base);
                    v = (t->states[r31] == 1);
                }

                u8 pick = v ? e[0x79] : 0xFF;
                cond = (pick == localIdx());
            }

            u8 result;
            if (cond != 0 && ((*flag >> 7) & 1)) {
                result = 0;
            } else if (player == 4) {
                result = 0;
            } else if (player > 4) {
                result = 0;
            } else {
                u8* g = getSelected(base);
                int v2;
                if ((g + player)[0x68] != 1) {
                    v2 = 0;
                } else {
                    s32 w = *(s32*)(g + 0x84 + player * 0x18 + sub * 8);
                    v2 = ((w >> 24) == 1);
                }

                if (v2)
                    result = (base + player * 0x218)[0xC5];
                else
                    result = 0;
            }

            if (result)
                count++;
        }

        i++;
        slot += 8;
        flag += 8;
    } while (i < 4);

    return count;
}
