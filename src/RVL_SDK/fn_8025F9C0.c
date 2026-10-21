#pragma force_active on
typedef unsigned int u32;

extern void (*lbl_805A0E6C)(int, void*);

void fn_8025F9C0(int interrupt, void* context)
{
    *(u32*)0xCC003000 = 0x1000;
    if (lbl_805A0E6C != 0) {
        lbl_805A0E6C(interrupt, context);
    }
}
