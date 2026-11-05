#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_80033744(void*, int, int);
extern "C" void* lbl_805A0088;

extern "C" void* fn_800334E4(int arg0, int arg1) {
    void* var_r3;

    if (lbl_805A0088 == 0) {
        var_r3 = __nw__FUlQ25Heaps8HeapType(0x16C, arg0);
        if (var_r3 != 0) {
            var_r3 = fn_80033744(var_r3, arg0, arg1);
        }
        lbl_805A0088 = var_r3;
    }
    return lbl_805A0088;
}