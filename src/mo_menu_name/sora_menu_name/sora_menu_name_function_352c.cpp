#include <types.h>
#pragma force_active on
extern "C" void fn_16_32E8(void*, u16, u16);
struct Entry {
    u8 used : 1;
    u8 rest : 7;
    u8 pad;
    s16 value;
};
struct Data {
    u8 pad[0x1EC];
    u16 x;
    u16 y;
    Entry entries[122];
    u16 count;
    s32 find(s32 arg) {
        Entry* p = entries;
        s32 i = 0;
        for (; i < count; i++, p++) {
            if (p->value != -1 && p->value != -2 && p->value == arg) break;
        }
        return i < count ? i : -1;
    }
};
extern "C" s32 fn_16_352C(Data* self, s32 arg) {
    s32 idx = self->find(arg);
    if (idx < 0) return 1;
    if (self->entries[idx].used == 1) return 2;
    self->entries[idx].used = 1;
    fn_16_32E8(self, self->x, self->y);
    return 0;
}