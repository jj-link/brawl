#pragma force_active on
extern "C" void fn_8005F758(int *p, int arg1) {
    if (arg1 == 0xFF) {
        p[0x48 / 4] = 3;
        return;
    }
    p[0x48 / 4] = arg1;
}
