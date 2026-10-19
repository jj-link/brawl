#pragma force_active on
extern "C" {
    void fn_27_B156C(void *, int, void *);
}

extern "C" void fn_41_1350C(void *r3, int r4)
{
    int r5 = r4;
    r4 = 1;
    r3 = (char *)r3 + 0x44;
    fn_27_B156C(r3, r4, (void *)r5);
}
