#pragma force_active on
extern int fn_80378084();

int fn_803741F8(int dummy, void **arg1) {
    int temp = fn_80378084();
    if (temp) {
        return temp;
    }
    *(int *)((char *)(*arg1) + 0xc) = 2;
    *(int *)((char *)(*arg1) + 0x10) = 0;
    return 0;
}
