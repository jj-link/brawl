#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on
#pragma switch_tables on
extern char lbl_80414180[];
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(const char*, s32, void*, s32, s32);
    virtual void slot3(const char*, s32, void*);
};
struct Data {
    u8** entries;
    s32 count;
    char pad[8];
    s32 lastSize;
    char pad2[2];
    u16 size;
};
extern "C" void fn_802FEB48(Data* self, Object_vptr_0* visitor) {
    u8* end;
    s32 offset;
    s32 i = 0;
    offset = 0;
    for (; i < self->count - 1; ++i) {
        visitor->slot2(lbl_80414180 + 6, 8, *(u8**)((u8*)self->entries + offset), self->size, self->size);
        offset += 4;
    }
    if (i < self->count)
        visitor->slot2(lbl_80414180 + 6, 8, self->entries[i], self->lastSize, self->size);
    s32 j = 0;
    offset = 0;
    for (; j < self->count;) {
        u8* cursor = *(u8**)((u8*)self->entries + offset);
        ++j;
        offset += 4;
        if (j == self->count)
            i = (s32)(cursor + self->lastSize);
        else
            i = (s32)(cursor + self->size);
        while (cursor < (u8*)i) {
            switch (*cursor) {
            case 6:
                visitor->slot3(lbl_80414180, 8, *(void**)(cursor + 4));
            case 2:
            case 4:
                visitor->slot3(lbl_80414180 + 13, 8, *(void**)(cursor + 0x10));
            case 0:
            advance:
                cursor += cursor[3];
                break;
            default:
                goto advance;
            }
        }
    }
}
