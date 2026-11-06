#pragma force_active on
extern int gUnk805a03d8;
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_8014C180(void*);
extern "C" void fn_8014C26C(void*, int, int);

extern "C" {
void fn_80147434() {
    int v = gUnk805a03d8;
    int flag = 0;
    if (v >= 3 && v <= 6) {
        flag = 1;
    }
    if (flag != 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x48, 6);
        if (p != 0) {
            p = fn_8014C180(p);
        }
        if (p != 0) {
            fn_8014C26C(p, 6, 1);
        }
    }
}
}
