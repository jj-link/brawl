#include <types.h>
#include <string.h>
#pragma force_active on

extern s32 fn_8035A590(s32);
extern s32 fn_8035A598(s32, s32);
extern u32 fn_80388958(s32);
extern u32 fn_80388968(s32);
extern s32 fn_803A7AF4(s32);

typedef void (*FnHandler)(void*, s32, u32, s32, s32, void**, s32);

static inline s32 findItem(void* self, u32 key32, u16 key16, s32 *cur, s32 *idx) {
    s32 n = fn_8035A590(*(s32*)((char*)self + 4));
    for (*idx = 0; *idx < n; (*idx)++) {
        *cur = *(s32*)fn_8035A598(*(s32*)((char*)self + 4), *idx);
        if (fn_80388958(*cur) == key32 && (u16)fn_80388968(*cur) == key16) {
            return *idx;
        }
    }
    return -1;
}

static inline s32 findNul(const s8* q, s32 len) {
    s32 i = 0;
    for (; i < len; i++, q++) {
        if (*q == 0) {
            return i + 1;
        }
    }
    return -1;
}

s32 fn_8038C4FC(void* self, char* data, s32 size)
{
    u16 tmp16;
    u32 tmp32;
    u32 pair[2];
    u32 key32;
    u16 key16;
    void* arr[16];
    s32 k;
    s32 n;
    s32 i;
    s32 count;
    s32 len;
    s32 cur;
    s32 item;
    u8 nStr;
    FnHandler handler;
    void** out;

    if (size < 0xb) {
        return 4;
    }

    memcpy(&tmp32, data, 4);
    memcpy(&tmp16, data + 4, 2);
    key16 = tmp16;
    key32 = tmp32;
    i = findItem(self, key32, key16, &cur, &i);
    if (i == -1) {
        return 0;
    }
    item = *(s32*)fn_8035A598(*(s32*)((char*)self + 4), i);
    memcpy(&pair[0], data + 6, 4);
    pair[1] = fn_803A7AF4(pair[1]);
    pair[0] = 0;
    size -= 0xb;
    nStr = data[10];
    data += 0xb;
    count = 0;
    out = arr;
    while (count < nStr && count < 0x10) {
        if (size < 1) {
            break;
        }
        for (k = 0; k < size; k++) {
            if (data[k] == 0) {
                len = k + 1;
                goto have_len;
            }
        }
        len = -1;
have_len:
        if (len == -1) {
            return 4;
        }
        *out = data;
        data += len;
        size -= len;
        out++;
        count++;
    }
    handler = *(FnHandler*)((char*)self + 0x48c);
    if (handler == 0) {
        return 0;
    }
    handler(self, item, pair[0], pair[1], count, arr, *(s32*)((char*)self + 0x494));
    return 0;
}
