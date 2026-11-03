#pragma force_active on
#pragma use_lmw_stmw on
#include <string.h>
typedef struct Entry { u16 bits, value; } Entry;
typedef struct State {
    u32 data;
    s32 count;
    u8 pad08[0x47c];
    Entry *dc;
    s32 dc1, dc2;
    u8 pad490[4];
    Entry *ac;
    s32 ac1, ac2;
    u8 pad4a0[0x1380];
    s32 limit, size;
} State;
extern s32 fn_80261178(State *);
extern s32 fn_802656B8(s32, s32, State *);
extern u8 lbl_8040DD10[];

s32 fn_8026541C(s32 *out, s32 *quant, s32 *pred, State *s)
{
    Entry *dc = s->dc;
    Entry *ac;
    s32 runsize, index, limit, a, b;
    s32 result;
    u32 mask, bits, value;
    Entry *entry;

    if (s->count <= 8) {
        result = fn_80261178(s);
        if (result < 0) return result;
    }
    {
    s32 count = s->count;
    s32 idx = (s->data >> (count - 8)) & 255;
    u16 len = dc[idx].bits;
    if (len != 0) {
        dc = (Entry *)(u32)dc[idx].value;
        s->count = count - len;
    } else {
        dc = (Entry *)fn_802656B8(s->dc1, s->dc2, s);
        if ((s32)dc < 0) return (s32)dc;
    }
    }
    if (dc != 0) {
        if (s->count <= (s32)dc) {
            result = fn_80261178(s);
            if (result < 0) return result;
        }
        bits = 1 << (s32)dc;
        mask = bits - 1;
        s->count -= (s32)dc;
        value = (s->data >> s->count) & mask;
        if ((bits >> 1) > value) value -= mask;
        *pred += value;
    }
    *out = *pred * *quant;
    ac = s->ac;
    a = s->ac1;
    b = s->ac2;
    limit = s->limit;
    memset(out + 1, 0, s->size);
    index = 1;
    do {
        if (s->count <= 8) {
            result = fn_80261178(s);
            if (result < 0) return result;
        }
        entry = &ac[(s->data >> (s->count - 8)) & 255];
        if (entry->bits != 0) {
            result = entry->value;
            s->count -= entry->bits;
        } else {
            result = fn_802656B8(a, b, s);
            if (result < 0) return result;
        }
        runsize = result & 15;
        if (runsize != 0) {
            index += result >> 4;
            if (s->count <= runsize) {
                result = fn_80261178(s);
                if (result < 0) return result;
            }
            if (index > limit) {
                s->count -= runsize;
                if (index >= 64) return -100;
                index++;
            } else {
                mask = 1 << runsize;
                bits = mask - 1;
                s->count -= runsize;
                value = (s->data >> s->count) & bits;
                if ((mask >> 1) > value) value -= bits;
                if (index >= 64) return -100;
                runsize = lbl_8040DD10[index++];
                out[runsize] = value * quant[runsize];
            }
        } else {
            if (result == 0) return 0;
            index += 16;
        }
    } while (index < 64);
    return 0;
}