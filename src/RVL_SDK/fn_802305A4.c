#pragma force_active on
extern void fn_80231BB4(signed char);

void fn_802305A4(int a, signed char b) {
    if (a == 4)
        goto callit;
    if (a >= 4)
        return;
    if (a == 0)
        return;
    return;
callit:
    fn_80231BB4(b);
}
