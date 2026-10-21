#pragma force_active on
typedef unsigned short u16;
typedef int s32;

extern unsigned char* fn_801DC7C0(int mode, unsigned char* str, int* table, int* result);
extern u16 lbl_8059E9E0;
extern void* lbl_805A06B0;

u16 fn_801DC2C4(void)
{
    s32 value;

    if (lbl_8059E9E0 == 0xFFFF) {
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

    return lbl_8059E9E0;
}
