#pragma force_active on
extern void fn_801DD2A0(unsigned int);

int fn_801DE398(int arg0) {
    if (arg0 != 0) {
        *(unsigned short *)0xCC004010 = 0xFF;
        fn_801DD2A0(0xF0000000);
    }
    return 1;
}
