#pragma force_active on
extern char lbl_27_bss_3210[];

extern "C" int fn_27_14954C(int p1, int p2)
{
    if (p2 == 0x21) {
        goto L1;
    }
    if (p2 >= 0x21) {
        goto L1;
    }
    if (p2 == 5) {
        goto L2;
    }
L1:
    return *(int*)(*(int*)(lbl_27_bss_3210 + 0x18c) + 0x7c);
L2:
    return *(int*)(*(int*)(lbl_27_bss_3210 + 0x3c) + 0x108);
}
