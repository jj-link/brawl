#pragma force_active on
extern char lbl_80529994[];

void fn_802340AC(int a)
{
    void (*f)(int, int) = *(void (**)(int, int))(lbl_80529994 + 0x50);
    if (f == 0) {
        return;
    }
    f(0, a);
}
