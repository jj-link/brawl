#include <types.h>
#pragma force_active on

typedef struct {
    u16 limit;
    u16 base;
} Entry;

typedef struct {
    u32 data;
    s32 count;
} State;

extern s32 fn_80261178(State *);

s32 fn_802656B8(Entry *table, s32 values, State *s)
{
    Entry entry;
    Entry temp;
    Entry *p;
    u32 code;
    u32 length;
    s32 result;

    if (s->count <= 17) {
        result = fn_80261178(s);
        if (result < 0) return result;
    }
    p = table + 9;
    length = 9;
    code = (s->data >> (s->count -= 9)) & 511;
    while (code > (entry = *p).limit) {
        length++;
        p++;
        if (length > 16) return -100;
        code <<= 1;
        code |= (s->data >> --s->count) & 1;
    }
    result = code - entry.limit;
    result += entry.base;
    return *(u8 *)(values + result);
}
