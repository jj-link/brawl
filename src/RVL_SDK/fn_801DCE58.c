#pragma force_active on
typedef unsigned short u16;
typedef int s32;
extern void fn_801DC7C0(void);
extern u16 lbl_8059E9E0;
extern unsigned char* (*lbl_805A06B0)(int, int, void*, void*);

static inline u16 get(void)
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

unsigned char* fn_801DCE58(int arg0, s32* out)
{
    char* a;
    unsigned char* b;
    unsigned char* r;
    u16 v = get();
    r = lbl_805A06B0(v, arg0, &a, &b);
    if (out != 0) {
        *out = *(unsigned char*)((a + *(u16*)(a + 0x22)) + (int)b);
    }
    return r;
}
