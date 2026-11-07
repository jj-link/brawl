#include <ec/ec_mgr.h>
#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" ecMgr* fn_8005E6C8(void*, int, int, int);
extern "C" void fn_801EC158(void*);
extern unsigned char lbl_80407060[];
extern void* lbl_80449F98[];
extern void** lbl_80497840[];
extern char lbl_80497810[];

extern "C" void fn_8005E5E8(int a, int b, int c) {
    unsigned char* p = lbl_80407060;
    void*** out = lbl_80497840;
    unsigned char n;
    int index = 1;
    for (int i = 0; i < 0x137; ++i) {
        n = *p;
        if (n == 0) {
            *out = 0;
        } else {
            *out = &lbl_80449F98[index];
            index += n;
        }
        ++p;
        ++out;
    }
    fn_801EC158(lbl_80497810);
    if (g_ecMgr == 0) {
        void* obj = __nw__FUlQ25Heaps8HeapType(0xA8, 3);
        if (obj != 0) {
            obj = fn_8005E6C8(obj, a, b, c);
        }
        g_ecMgr = (ecMgr*)obj;
    }
}