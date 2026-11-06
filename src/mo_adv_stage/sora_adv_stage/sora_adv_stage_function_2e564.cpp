#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int type);
extern "C" int fn_40_10A38(void* p, int a4, int a5, int a6, int a7);
extern "C" void fn_27_233F58(void* a, void* b);
extern "C" void fn_27_233FCC(void* a, void* b);

extern "C" void fn_40_2E564(int* arg0, void* arg1, void* arg2, void* arg3, int arg4, int arg5) {
    int v;
    v = (int)__nw__FUlQ25Heaps8HeapType(0x20, 0xf);
    if (v) {
        v = fn_40_10A38((void*)v, (int)arg1, arg4, (((unsigned char*)arg3)[2] != 0), arg5);
    }
    int* p = (int*)arg0 + arg4;
    p[2] = v;
    if (arg4 == 1) {
        fn_27_233F58(arg2, (void*)p[2]);
    } else {
        fn_27_233FCC(arg2, (void*)p[2]);
    }
}