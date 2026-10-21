#pragma force_active on
extern "C" void fn_802FBF38(void* arg1, unsigned short* arg2, unsigned short arg3) {
    unsigned short* ptr = arg2;
    for (int i = 0; i < 3; ++i) {
        if (*ptr == 0xFFFF) {
            arg2[i] = arg3;
            return;
        }
        ptr++;
    }
}
