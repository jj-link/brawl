#pragma force_active on

typedef unsigned short u16;
typedef int s32;

extern void fn_801DC7C0(void);
extern void fn_801DC8BC(void);
extern u16 lbl_8059E9E0;
extern void* lbl_805A06B0;

static inline u16 get_encoding(void)
{
    s32 value;

    if (lbl_8059E9E0 != 0xFFFF) {
        return lbl_8059E9E0;
    }

    {
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
}

u16 fn_801DC318(u16 arg0)
{
    u16 ret = get_encoding();

    if (arg0 <= 5) {
        lbl_8059E9E0 = arg0;
        if (arg0 >= 3 && arg0 <= 5) {
            lbl_805A06B0 = (void*)fn_801DC8BC;
        }
    }

    return ret;
}
