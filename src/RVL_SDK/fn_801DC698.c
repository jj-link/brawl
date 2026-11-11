#pragma force_active on

typedef unsigned short u16;
typedef int s32;

extern unsigned char* fn_801DC7C0(int mode, unsigned char* str, int* table, int* result);
extern s32 fn_801DC398(s32 a, s32 b, s32 c);
extern u16 lbl_8059E9E0;
extern void* lbl_805A06B0;
extern s32 lbl_805A06B8;
extern s32 lbl_805A06BC;

static inline u16 get_encoding(void)
{
    s32 value;

    if (lbl_8059E9E0 != 0xFFFF) {
        return lbl_8059E9E0;
    }

    switch (*(s32*)0x800000CC) {
    case 0:
        value = (*(u16*)0xCC00206E >> 1) & 1;
        lbl_8059E9E0 = value;
        break;
    case 1:
    case 2:
    default:
        value = 0;
        lbl_8059E9E0 = 0;
        break;
    }

    lbl_805A06B0 = (void*)fn_801DC7C0;
    return (u16)value;
}

s32 fn_801DC698(s32 arg0, s32 arg1)
{
    s32 res;
    s32 tmp;

    switch (get_encoding()) {
    case 0:
        lbl_805A06BC = arg0;
        res = fn_801DC398(arg1, 0, arg0);
        break;
    case 1:
        lbl_805A06B8 = arg0;
        res = fn_801DC398(arg1, 1, arg0);
        break;
    case 3:
    case 4:
    case 5:
        lbl_805A06BC = arg0;
        res = fn_801DC398(arg1, 0, arg0);
        if (res != 0) {
            tmp = lbl_805A06BC + res;
            lbl_805A06B8 = tmp;
            res += fn_801DC398(arg1, 1, tmp);
        }
        break;
    default:
        res = 0;
        break;
    }

    return res;
}