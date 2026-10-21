#pragma force_active on
extern void *fn_80251AD0(void *a, unsigned short b);
extern void fn_802533C8(void *a, int b, int c);

void fn_80254A5C(void *arg0, unsigned short arg1, int arg2) {
    fn_802533C8(fn_80251AD0(arg0, arg1), 0xE, arg2);
}
