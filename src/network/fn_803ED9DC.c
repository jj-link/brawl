#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct Entry {
    u32 handle;
    unsigned char pad04[0x50];
    u32 length;
    unsigned char file[0x94];
    int error;
} Entry;
extern Entry lbl_805980D8[];
extern int fn_8020B16C(void *, u32 *);
extern int fn_8020AC38(void *, u32, int);
extern int fn_8020AA78(void *, void *, u32);
extern void fn_803D6224(void *, const void *, u32);
static inline void set_error(u32 handle, int error)
{
    u16 i;
    for (i = 0; i < 23; ++i) {
        if ((void *)lbl_805980D8[i].handle == (void *)handle) {
            lbl_805980D8[i].error = error;
            break;
        }
    }
}
int fn_803ED9DC(u32 count, unsigned char *dest, u32 offset, u32 size, u32 *out, u32 handle)
{
    unsigned char buffer[512] __attribute__((aligned(32)));
    u32 position;
    u16 i;
    int result;
    u32 length, start, remaining;
    u32 done;
    Entry *entry = 0;
    for (i = 0; i < 23; ++i) {
        if ((void *)lbl_805980D8[i].handle == (void *)handle) {
            entry = &lbl_805980D8[i];
            break;
        }
    }
    result = i == 23 ? -22 : 0;
    if (result != 0)
        return -20;
    remaining = count * size;
    length = entry->length;
    start = offset * size;
    if (fn_8020B16C(entry->file, &position) != 0 || position != start)
        result = fn_8020AC38(entry->file, start, 0);
    else
        result = 0;
    if (result >= 0) {
        if (start + remaining > length) {
            remaining = length - start;
            done = 0;
            while (remaining >= 512) {
                result = fn_8020AA78(entry->file, buffer, 512);
                if (result < 0)
                    return -22;
                fn_803D6224(dest + done, buffer, result);
                done += result;
                remaining -= result;
            }
            if (remaining != 0) {
                result = fn_8020AA78(entry->file, buffer, remaining);
                if (result < 0)
                    return -22;
                fn_803D6224(dest + done, buffer, result);
            }
            return -22;
        }
        done = 0;
        while (remaining >= 512) {
            result = fn_8020AA78(entry->file, buffer, 512);
            if (result < 0) {
                set_error(handle, result);
                return result;
            }
            fn_803D6224(dest + done, buffer, result);
            done += result;
            remaining -= result;
        }
        if (remaining != 0) {
            result = fn_8020AA78(entry->file, buffer, remaining);
            if (result < 0) {
                set_error(handle, result);
                return result;
            }
            fn_803D6224(dest + done, buffer, result);
        }
        *out = count;
        return 0;
    }
    set_error(handle, result);
    return result;
}