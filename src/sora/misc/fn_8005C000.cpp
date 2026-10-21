#pragma force_active on
extern "C" {
void fn_8005C000(int unused, int* arg1) {
    arg1[2] = arg1[2] + 0x10000;
}
}
