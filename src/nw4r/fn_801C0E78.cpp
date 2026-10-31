#pragma force_active on
extern "C" int fn_801C6C34(void *a, int b, int c, int *d);
extern "C" int fn_801C6C1C(void *a, int b, int *c);
extern "C" int fn_801C6C24(void *a, int b, int c, int *d);

extern "C" int fn_801C0E78(void *arg0, int arg1) {
    int buf[14];

    if (fn_801C6C34(arg0, arg1, 0, &buf[0]) == 0) {
        return 0;
    }
    if (fn_801C6C1C(arg0, buf[0], &buf[8]) == 0) {
        return 0;
    }
    if (fn_801C6C24(arg0, buf[0], buf[1], &buf[2]) == 0) {
        return 0;
    }
    if (buf[9] != 0) {
        return 0;
    }
    int s = buf[12] + buf[5];
    return s + *(int *)((char *)arg0 + 0x108);
}
