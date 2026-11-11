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

unsigned char* fn_801DCD08(int arg0, void** out, int* x, int* y, int* z)
{
    char* a;
    int b;
    int page, total, row, col;
    unsigned char* result;
    u16 v = get();

    result = lbl_805A06B0(v, arg0, &a, &b);
    page = b / (*(u16*)(a + 0x1a) * *(u16*)(a + 0x1c));
    *out = a + *(int*)(a + 0x24) + *(int*)(a + 0x14) * page;
    total = b - page * (*(u16*)(a + 0x1a) * *(u16*)(a + 0x1c));
    row = total / *(u16*)(a + 0x1a);
    col = total - row * *(u16*)(a + 0x1a);
    *x = col * *(u16*)(a + 0x10);
    *y = row * *(u16*)(a + 0x12);

    if (z != 0) {
        *z = *(unsigned char*)(a + *(u16*)(a + 0x22) + b);
    }

    return result;
}
