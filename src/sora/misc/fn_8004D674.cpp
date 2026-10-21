#include <types.h>
#pragma force_active on

extern "C" void* memcpy(void*, const void*, unsigned long);

struct Entry {
    u8 m_pad[0xE0];
    u16 m_size;
    u8 m_data[0x42];
};

struct Owner {
    u8 m_pad[0x28];
    Entry* m_entries;
};

extern "C" bool fn_8004D674(Owner* obj, int index, Entry* out) {
    Entry* e = obj->m_entries + index;
    if (e->m_size == 0) {
        return false;
    }
    memcpy(out, (void*)&e->m_size, 12);
    return true;
}
