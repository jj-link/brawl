#pragma force_active on
extern int fn_803C7DE8(void*, int);
extern void fn_803AC820(void*);

int fn_803CA980(void* arg0) {
    if (arg0 == 0) {
        return -0x14;
    }
    fn_803C7DE8(arg0, 1);
    fn_803AC820(arg0);
    return 0;
}
