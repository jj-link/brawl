#include <types.h>
#pragma force_active on
extern "C" u8 lbl_27_data_60AE8[];
struct Entry {
    u32 value;
    u32 flags;
    void reset() {
        value = 0;
        flags |= 0xFFFF0000;
        flags |= 0xFFFF;
    }
};
struct Object {
    void* data;
    void* dataEnd;
    u32 hi : 13;
    u32 lo : 19;
    Entry entries[4];
};
inline void resetEntries(u8* begin, u8* end) {
    u8* p = begin;
    do {
        ((Entry*)p)->reset();
        p += 8;
    } while (p < end);
}
extern "C" Object* fn_27_291DA0(Object* self) {
    self->data = lbl_27_data_60AE8;
    self->dataEnd = lbl_27_data_60AE8 + 0x48;
    self->hi = 0;
    resetEntries((u8*)self->entries, (u8*)(self->entries + 4));
    return self;
}