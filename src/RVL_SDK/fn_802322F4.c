#pragma force_active on
typedef void (*FnPtr)(int, int, int, int);

extern int lbl_80529858[0x90 / 4];

void fn_802322F4(int a, int b, int c)
{
    FnPtr f = (FnPtr)lbl_80529858[0x84 / 4];
    if (f == 0) {
        return;
    }
    f(6, a, b, c);
}
