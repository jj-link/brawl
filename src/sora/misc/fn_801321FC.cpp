#pragma force_active on

extern "C" {
int fn_80041884(int, int, int);

int fn_801321FC(int arg0) {
    return fn_80041884(arg0 + 0x344, arg0 + 0x354, arg0 + 0x344);
}
}
