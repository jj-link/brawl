#pragma force_active on
extern "C" int fn_801C2438(unsigned char* arg0, unsigned char arg1) {
    if (arg0[0] == 0)
        return 0;
    arg0[2] = arg1;
    return 1;
}
