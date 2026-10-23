#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern s32 fn_803A1CDC(void);
extern void fn_80397748(void *, int, int);
extern s32 fn_803A1DF4(void *);

static inline s32 test_bit(u32 index)
{
    u8 *data;
    s32 result = fn_803A1DF4(&data);

    if (result != 0) {
        return result;
    }
    return (*(u32 *)(data + ((index >> 3) & 0x1FFFFFFC) + 0x10)
            >> (index & 31)) & 1;
}

s32 fn_803A19D8(s32 *arg0, u32 arg1)
{
    s32 result = fn_803A1CDC();

    if (result != 0) {
        return result;
    }
    if ((u32)arg0[0] == 1U) {
        fn_80397748((u8 *)arg0 + 0x48, 0, 0xF8);
    }
    if (test_bit(arg1) == 1) {
        arg0[1] = 2;
    }
    return 0;
}
