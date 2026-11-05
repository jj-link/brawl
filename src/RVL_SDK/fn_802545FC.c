#pragma force_active on
extern void *fn_80251AD0(void *, int);
extern void fn_8025111C(void *, int);
extern void fn_802533C8(void *, int, void *);

void fn_802545FC(void *arg0, int arg1, int arg2, unsigned short arg3) {
    unsigned short local = arg3;
    void *result = fn_80251AD0(arg0, arg1);
    if (((unsigned char *)arg0)[0x6C] != 5 && local == 0) {
        fn_8025111C(arg0, arg1);
    } else {
        fn_802533C8(result, 0xB, &local);
    }
}