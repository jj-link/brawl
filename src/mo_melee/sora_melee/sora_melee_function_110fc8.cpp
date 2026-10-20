#include <types.h>
#pragma force_active on

class ftEntry {
public:
    char _0x00[0x54];
    int m_playerNo;
};

class Manager {
public:
    ftEntry* m_entry;
};

extern "C" int fn_27_110FC8(Manager* self) {
    return self->m_entry->m_playerNo;
}
