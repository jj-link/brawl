#pragma force_active on
extern void fn_80269308(void *, unsigned short);
extern void fn_802692BC(void *, unsigned char);
int fn_8026BB2C(void *arg0) {
    void *p = (char *)arg0 + 0x1634;
    fn_80269308(p, (unsigned short)-38);
    fn_80269308(p, 12);
    fn_802692BC(p, 3);
    fn_802692BC(p, 0);
    fn_802692BC(p, 0);
    fn_802692BC(p, 1);
    fn_802692BC(p, 17);
    fn_802692BC(p, 2);
    fn_802692BC(p, 17);
    fn_802692BC(p, 0);
    fn_802692BC(p, 63);
    fn_802692BC(p, 0);
    return 0;
}