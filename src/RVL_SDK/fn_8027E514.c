#pragma force_active on
extern char lbl_80486378[];

void fn_8027E514(void *arg0) {
    *(short *)((char *)arg0 + 6) = 1;
    *(char **)arg0 = lbl_80486378;
}
