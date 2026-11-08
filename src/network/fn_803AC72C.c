#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Slot { u8 pad[12]; u32 generation; u8 pad2[32]; int value; } Slot;
typedef struct Entry { u32 generation; Slot *slot; } Entry;
typedef struct State { u32 pad; Entry entries[26]; u8 pad2[0xD0]; Slot slots[26]; } State;
extern State lbl_8053A6E0;
static inline int invalid(u32 a)
{
    Slot *slot;
    u16 i;
    u32 index = a & 0xFF;
    u32 type = a & 0xFF00;
    u32 generation = a >> 16;
    if (index >= 26 || type != 0x300 ||
        generation > lbl_8053A6E0.slots[index].generation)
        return 1;
    slot = &lbl_8053A6E0.slots[index];
    for (i = 0; i < 26; ++i) {
        if (lbl_8053A6E0.entries[i].slot == slot &&
            (a >> 16) == lbl_8053A6E0.entries[i].generation)
            break;
    }
    return i >= 26;
}
int fn_803AC72C(int arg0, int arg1)
{
    u32 index;
    int result;
    if (arg0 == 0 || arg1 == 0)
        return 1;
    index = (u32)arg0 & 0xFF;
    result = invalid((u32)arg0);
    if (result == 0) {
        lbl_8053A6E0.slots[index].value = arg1;
        return 0;
    }
    return result;
}