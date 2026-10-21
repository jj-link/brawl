#pragma force_active on
extern void fn_803ADB4C(int, int *);

int fn_803AA514(char *arg0) {
    int sp8;

    fn_803ADB4C(*(int *)(arg0 + 0x188C), &sp8);
    return sp8;
}
