#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

struct Fn27Entry {
    u8 pad0[6];
    u16 flags;
    u8 pad1[0x24 - 8];
};

extern "C" {
void* fn_27_21C8D4(Fn27Entry* table, int index)
{
    if (index >= 0 && index < 0x20) {
        Fn27Entry* entry = &table[index];
        if (entry->flags & 1) {
            return entry;
        }
    }
    return 0;
}
}
