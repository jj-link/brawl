#include <types.h>
#pragma force_active on

extern "C" void* memcpy(void*, const void*, unsigned long);
extern "C" void fn_8006BCA8(void*, const void*);

struct Entry {
    u8 m_pad[0xE0];
    u16 m_size;
    u8 m_data[0x42];
};

struct Owner {
    u8 m_pad[0x28];
    Entry* m_entries;
};

extern "C" bool fn_8004D6C4(Owner* obj, int index, void* out) {
    u8 buf[12];
    Entry* e = obj->m_entries + index;
    int ret;
    if (e->m_size == 0) {
        ret = 0;
    } else {
        memcpy(buf, (void*)&e->m_size, 12);
        ret = 1;
    }
    if (ret != 0) {
        fn_8006BCA8(out, buf);
        return true;
    }
    return false;
}
