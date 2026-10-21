#pragma force_active on
extern "C" {
int fn_800F4048(char* self) {
    int r0;
    goto test;
load:
    return *(int*)(self + 0x60);
test:
    r0 = *(int*)(self + 0x70);
    if (r0 == 6) {
        goto load;
    }
    if (r0 == 1) {
        goto load;
    }
    return 8;
}
}
