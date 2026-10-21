#pragma force_active on
extern "C" void fn_802FBEF8(void *unused, unsigned short *arr, unsigned long key) {
    unsigned short *p = arr;
    int i;
    for (i = 0; i < 3; i++) {
        if (key == *p) {
            arr[i] = 0xFFFF;
            return;
        }
        p++;
    }
}
