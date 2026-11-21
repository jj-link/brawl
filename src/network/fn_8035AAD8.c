#include <types.h>
#pragma force_active on

typedef struct {
    s32 count;
    s32 unk4;
    s32 size;
    s32 unkC;
    s32 unk10;
    u8* base;
} Table;

typedef s32 (*CmpFn)(void*, void*);

static inline s32 search_table(s32* foundp, Table* tbl, void* key, CmpFn cmp, s32 index, s32 flag)
{
    s32 count;
    u8* result;

    if (tbl == NULL || (count = tbl->count) == 0)
        return -1;
    if (flag != 0) {
        s32 base, size, mid, hi, lo, c;

        if (index < 0 || index >= count)
            base = 0;
        else
            base = (s32)(tbl->base + (s32)tbl->size * index);
        size = tbl->size;
        hi = count - index - 1;
        lo = 0;
        *foundp = 0;
        while (lo <= hi) {
            mid = (lo + hi) >> 1;
            c = cmp((void*)(base + mid * size), key);
            if (c == 0)
                *foundp = 1;
            if (c < 0)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        result = (u8*)base + (s32)lo * size;
    } else {
        u8* base;
        s32 n, size, i, off;

        if (index < 0 || index >= count)
            base = 0;
        else
            base = tbl->base + (s32)tbl->size * index;
        size = tbl->size;
        n = count - index;
        i = 0;
        off = 0;
        while (i < n) {
            if (cmp(key, base + off) == 0) {
                result = base + size * (s32)i;
                goto done;
            }
            off += size;
            i++;
        }
        result = 0;
    done:;
    }
    if (result != 0 && *foundp != 0)
        return (s32)(result - tbl->base) / tbl->size;
    return -1;
}

s32 fn_8035AAD8(Table* tbl, void* key, CmpFn cmp, s32 index, s32 flag)
{
    s32 found = 1;
    return search_table(&found, tbl, key, cmp, index, flag);
}