#include <types.h>
#pragma force_active on

struct Elem {
    u8 data[0x78];
};

struct Table {
    u32 header;
    u32 pad4;
    int count;
    Elem elems[1];
};

extern "C" {
void* fn_66_A5BC(Table* table, int index) {
    int i = (table->count >> 30) + index;
    if (i >= 1) {
        i -= 1;
    }
    return (u8*)table + 0xc + i * 0x78;
}
}
