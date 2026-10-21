#pragma force_active on
typedef unsigned int u32;
typedef int s32;

namespace Heaps {
    enum HeapType { HEAP_TYPE_2 = 2 };
}

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" s32 fn_80106810(s32, s32, s32);
extern "C" s32 g_IfAdvMngr;

extern "C" void fn_8010674C(s32 arg0, s32 arg1) {
    s32 var_r3;

    var_r3 = (s32)__nw__FUlQ25Heaps8HeapType(0x11C, 2);
    if (var_r3 != 0) {
        var_r3 = fn_80106810(var_r3, arg0, arg1);
    }
    g_IfAdvMngr = var_r3;
}
