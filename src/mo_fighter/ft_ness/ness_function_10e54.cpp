#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_101_70(void*, void*, int, int, int);

extern "C" void fn_101_10E54(void* unused, void* arg1, int arg2, int arg3, int arg4) {
    void* object = __nw__FUlQ25Heaps8HeapType(0x4AE28, arg2);
    if (object != 0) {
        fn_101_70(object, arg1, arg2, arg3, arg4);
    }
}
