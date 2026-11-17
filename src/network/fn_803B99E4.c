#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int fn_803B6F80(void *, void *);
extern int fn_803AFEDC(void *, u32, void **);
extern void fn_803AFC80(void *);

static u32 bswap32(u32 x)
{
    return (x >> 24) | ((x >> 8) & 0xFF00) |
           ((x << 8) & 0xFF0000) | (x << 24);
}

int fn_803B99E4(void *arg0, u32 arg1, u32 arg2, void **arg3)
{
    void *table;
    u32 loaded;
    u32 size;
    int result;
    u32 block;
    u32 shift;
    u32 offset;
    u32 value;
    u32 swapped;
    int (*callback)(u32);
    int callbackResult;
    u32 limit;
    u32 retries;

    result = 0;
    if (arg0 == 0)
        return 10;

    if (((arg1 < 2) || (arg1 >= *(u32 *)((u8 *)arg0 + 0x34) + 2)) &&
        arg1 != 0 && arg1 != 1)
        return 14;

    shift = *(u8 *)((u8 *)arg0 + 0x20);
    offset = arg1 * 4;
    table = *arg3;
    loaded = *(u32 *)((u8 *)arg0 + 0x28);
    block = (u16)(loaded + (offset >> shift));
    size = *(u16 *)arg0;
    limit = (u16)(offset & (size - 1));
    loaded = *(u32 *)((u8 *)table + 0x18);

    if (loaded > block ||
        loaded + *(u32 *)((u8 *)arg0 + 0x1600) <= block) {
        result = fn_803B6F80(arg0, table);
        if (result != 0)
            return result;

        retries = 1;
        value = *(u16 *)((u8 *)arg0 + 0x18);
        if (value & 0x80)
            retries = value & 7;

        do {
            result = fn_803AFEDC(arg0, block, arg3);
            if (result == 0x1000) {
                callback = *(int (**)(u32))((u8 *)arg0 + 0x1890);
                if (callback != 0) {
                    callbackResult =
                        callback(*(u32 *)((u8 *)arg0 + 0x1870));
                    if (callbackResult == 0)
                        goto next;
                    if (callbackResult == 1) {
                        value = *(u8 *)((u8 *)arg0 + 0x22);
                        if (value >= 2 && retries < value) {
                            retries++;
                            block += *(u32 *)((u8 *)arg0 + 0x0C);
                            goto next;
                        }
                    }
                }
            }
            if (result != 0)
                return result;
        next:
            ;
        } while (result != 0);
    } else {
        if (block != loaded +
                         ((int)(*(u32 *)((u8 *)table + 8) -
                                *(u32 *)((u8 *)table + 4)) >> shift))
            *(u32 *)((u8 *)table + 8) += size;
    }

    {
        u32 *data = (u32 *)*(u32 *)((u8 *)*arg3 + 8);
        value = *(u32 *)((u8 *)data + limit);
        swapped = bswap32(value);
        value = (arg2 & 0x0FFFFFFF) | (swapped & 0xF0000000);
        swapped = bswap32(value);
        *(u32 *)((u8 *)data + limit) = swapped;
    }

    fn_803AFC80(*arg3);
    return result;
}