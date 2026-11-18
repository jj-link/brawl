#include <types.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern "C" u8 fn_800C851C();
extern "C" int fn_800C8524();
extern "C" u8 fn_800C8548();
extern "C" void fn_800CD934(void*, u8);
extern "C" void fn_800D0AE0(void*, void*);
extern "C" void fn_80145B98(int, u8);
extern char lbl_80457158[];
extern int lbl_805A03A8;
extern signed char lbl_805A0414;

struct StatusWord {
    signed int state : 8;
    unsigned int rest : 24;
};
struct Slot {
    StatusWord w;
    u32 x;
};
struct Group {
    Slot s[3];
};
struct Entry {
    u8 pad[0x84];
    Group g[4];
};
inline u8 localIndex() {
    u8 index = fn_800C851C();
    if (index == 0xFF) index = 4;
    return index;
}
inline u8* selectedEntry(u8* self) {
    u8 index = fn_800C8548();
    if (index == 0xFF) return 0;
    return (u8*)((u32)self + 0x70 + index * 0x218);
}
inline int countSelected(u8* self) {
    int count;
    u8 i;
    Entry* entry = (Entry*)selectedEntry(self);
    if (entry == 0) {
        count = -1;
    } else {
        count = 0;
        for (i = 0; i < 4; i++) {
            for (u8 j = 0; j < 3; j++) {
                if (entry->g[i].s[j].w.state != 0) count++;
            }
        }
    }
    return count;
}
extern "C" int fn_800D5C58(u8* self, int slotIndex) {
    u8* slot;
    const char* const base = lbl_80457158;
    u8* selected;
    int offset;
    u8 value;
    if ((fn_800C8524() != 0 && lbl_805A0414 == 1) || localIndex() == 4) {
        if (slotIndex == 0 || slotIndex >= 4) return 0;
        u8* local = self + localIndex() * 0x218;
        u8* sel = self + localIndex() * 0x218;
        u8* slots = local + 0xA8;
        if (sel[0xDC] != 0xFF) {
            netReport(base + 0x1E30, sel[0xDC], sel[0xDD]);
            return 0;
        }
        if (countSelected(self) >= 4) {
            netReport(base + 0x1E6C);
            return 0;
        }
        int first = ((StatusWord*)(slots + 8))->state;
        int second;
        if (first > 1 || (second = ((StatusWord*)(slots + 0x10))->state) > 1) {
            netReport(base + 0x1E98);
            return 0;
        }
        u8 index = 0;
        if (first == 0) index = 1;
        else if (second == 0) index = 2;
        if (index == 0) {
            netReport(base + 0x1EDC);
            return 0;
        }
        ((StatusWord*)(slots + index * 8))->state = 1;
        slotIndex *= 8;
        ((StatusWord*)(self + slotIndex + 0x50))->state = 1;
        *(self + slotIndex + 0x4C) = localIndex();
        *(self + slotIndex + 0x4D) = index;
        netReport(base + 0x1F10, localIndex(), index);
        u8 count = 0;
        for (int i = 0; i < 4; i++) {
            if (((StatusWord*)(slots + i * 8))->state != 0) count++;
        }
        if (self[0xFD5] != count) {
            netReport(base + 0x1194, self[0xFD5], count);
            self[0xFD5] = count;
            self[0xFCA] |= 4;
            fn_800CD934(self, count);
        }
        return 1;
    }
    if (localIndex() == 4) {
        netReport(base + 0x1B78);
        return 0;
    }
    if (slotIndex != 0) {
        s8* e = (s8*)selectedEntry(self);
        int n;
        if (e == 0) n = 1;
        else {
            n = 0;
            if (e[0x68] == 1) n = 1;
            if (e[0x69] == 1) n++;
            if (e[0x6A] == 1) n++;
            if (e[0x6B] == 1) n++;
        }
        if (n < 2) {
            netReport(base + 0x1F50);
            return 0;
        }
    }
    {
        u8* local = self + localIndex() * 0x218;
        u8 host = fn_800C8548();
        if (host == 0xFF)
            selected = 0;
        else
            selected = (u8*)((u32)self + 0x70 + host * 0x218);
        if (selected == 0) {
            netReport(base + 0x1B90);
            return 0;
        }
        u8* slots = local + 0xA8;
        if (slotIndex == 0) {
            if ((self[0xFC9] >> 3) & 1) {
                u8* p = selected + localIndex() * 0x18;
                u8 hv = p[0x85];
                p[0x85] = 0x7B;
                *(selected + localIndex() + 0x68) = 2;
                hv = (hv + 1) % 255;
                ((StatusWord*)slots)->state = 2;
                slots[1] = hv;
                ((StatusWord*)(self + 0x50))->state = 3;
                self[0x4C] = localIndex();
                self[0x4D] = 0;
                self[0x4F] = hv;
                netReport(base + 0x1F70, localIndex(), hv);
            }
            u8 hostIndex = fn_800C8548();
            u8* q = self + localIndex() * 0x218;
            q[0xC6] |= 1;
            fn_800D0AE0(self, q);
            fn_80145B98(lbl_805A03A8, hostIndex);
            *(u16*)(self + 0xFDC) = 0x12C0;
            return 1;
        }
        if (selected[0x6C] != 0xFF) {
            netReport(base + 0x1FB8, selected[0x6C], selected[0x6D]);
            return 0;
        }
        offset = slotIndex * 8;
        slot = self + offset;
        if (slot[0x4C] != 0xFF) return 0;
        int state = ((StatusWord*)(slot + 0x50))->state;
        if (state == 1) {
            netReport(base + 0x1FF0, selected[0x6C], selected[0x6D]);
            return 0;
        }
        if (state == 3) {
            netReport(base + 0x2040);
            return 0;
        }
        if (countSelected(self) >= 4) {
            netReport(base + 0x1E6C);
            return 0;
        }
        int first = ((StatusWord*)(slots + 8))->state;
        int second;
        if (first > 1 || (second = ((StatusWord*)(slots + 0x10))->state) > 1) {
            netReport(base + 0x1E98);
            return 0;
        }
        u8 index = 0;
        if (first == 0) index = 1;
        else if (second == 0) index = 2;
        if (index == 0) {
            netReport(base + 0x1EDC);
            return 0;
        }
        Slot* remoteSlot = &((Entry*)selected)->g[localIndex()].s[index];
        value = (((u8*)remoteSlot)[1] + 1) % 255;
        ((StatusWord*)(slots + index * 8))->state = 2;
        ((u8*)&((Slot*)slots)[index])[1] = value;
        ((StatusWord*)(slot + 0x50))->state = 3;
        slot[0x4C] = localIndex();
        (self + offset)[0x4D] = index;
        (self + offset)[0x4F] = value;
        u8 selectedIndex = fn_800C8548();
        u8* q = self + localIndex() * 0x218;
        q[0xC6] |= 1;
        fn_800D0AE0(self, q);
        fn_80145B98(lbl_805A03A8, selectedIndex);
        netReport(base + 0x2068, localIndex(), index, value);
        return 1;
    }
}
