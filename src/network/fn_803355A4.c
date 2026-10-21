#pragma force_active on
typedef void (*FnPtr)(int, void*, int);
extern FnPtr lbl_805A0F58;

void fn_803355A4(void* p)
{
    if (p == 0) {
        return;
    }
    lbl_805A0F58(9, (char*)p - 0x20, 0);
}
