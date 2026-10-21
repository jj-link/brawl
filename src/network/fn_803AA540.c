#pragma force_active on
extern int fn_803AD92C(int, int*);

int fn_803AA540(void *arg0) {
    int local;
    fn_803AD92C(*(int *)((char *)arg0 + 0x188C), &local);
    return local;
}
