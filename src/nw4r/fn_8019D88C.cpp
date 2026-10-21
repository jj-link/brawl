#pragma force_active on
extern "C" {
extern void fn_80204E6C(void *a, void *b);
extern char lbl_804661D8[];

void *fn_8019D88C(void *arg0) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_804661D8;
        fn_80204E6C(*(void **)((char *)arg0 + 8), arg0);
    }
    return arg0;
}
}
