#pragma force_active on
extern "C" {
int fn_803EC094(int);

int fn_8001BCBC(void) {
    int result = 0;
    if (fn_803EC094(0x41) == 1) {
        result = 1;
    }
    return result;
}
}
