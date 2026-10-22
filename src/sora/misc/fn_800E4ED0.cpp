#pragma force_active on
extern "C" void fn_800E4FD0(char*, int, int);

extern "C" void fn_800E4ED0(char** arr, int n) {
    int i;
    char** q;
    int c1 = 0, c2 = 0, i1 = 0, i2 = 0;
    int idx, cnt;
    for (i = 0; i < n; i++) {
        char* p = arr[i];
        if (p) {
            switch (*(int*)(p + 0x2b0)) {
            case 1: c1++; break;
            case 2: c2++; break;
            case 0: break;
            }
        }
    }
    q = arr;
    for (i = 0; i < n; i++, q++) {
        char* p = *q;
        if (p) {
            switch (*(int*)(p + 0x2b0)) {
            case 1: idx = i1; cnt = c1; i1++; break;
            case 2: idx = i2; cnt = c2; i2++; break;
            case 0: break;
            }
            fn_800E4FD0(p, idx, cnt);
        }
    }
}
