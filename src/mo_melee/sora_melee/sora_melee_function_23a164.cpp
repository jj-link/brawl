#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_23B4F4(void*, int);
extern "C" void* fn_27_23F008(void*);
extern "C" void* fn_27_23FF58(void*);
extern "C" void* fn_27_241404(void*);
extern "C" void* fn_27_2418F4(void*);
extern "C" void* fn_27_2407E0(void*);
extern "C" void* fn_27_23EB70(void*, int);
extern "C" void* fn_27_23AC74(void*);
extern "C" void* fn_27_240538(void*);
extern "C" void* fn_27_241850(void*);
extern "C" void* fn_27_2416C0(void*);
extern "C" void* fn_27_240F70(void*);
extern "C" void* fn_27_240B14(void*);
extern "C" void* fn_27_241B14(void*);
extern "C" void* fn_27_24113C(void*);

#define C1(n, sz, f) case n: { void* p = __nw__FUlQ25Heaps8HeapType(sz, 2); if (p) p = f(p); return p; }

extern "C" void* fn_27_23A164(unsigned long t) {
    switch (t) {
    case 0: { void* p = __nw__FUlQ25Heaps8HeapType(0x60, 2); if (p) p = fn_27_23B4F4(p, 0); return p; }
    case 1: { void* p = __nw__FUlQ25Heaps8HeapType(0x60, 2); if (p) p = fn_27_23B4F4(p, 1); return p; }
    case 2: { void* p = __nw__FUlQ25Heaps8HeapType(0x60, 2); if (p) p = fn_27_23B4F4(p, 2); return p; }
    case 3: { void* p = __nw__FUlQ25Heaps8HeapType(0x60, 2); if (p) p = fn_27_23B4F4(p, 3); return p; }
    case 4: { void* p = __nw__FUlQ25Heaps8HeapType(0x60, 2); if (p) p = fn_27_23B4F4(p, 4); return p; }
    case 5: { void* p = __nw__FUlQ25Heaps8HeapType(0x60, 2); if (p) p = fn_27_23B4F4(p, 5); return p; }
    case 6: { void* p = __nw__FUlQ25Heaps8HeapType(0x60, 2); if (p) p = fn_27_23B4F4(p, 6); return p; }
    C1(7, 0xCC, fn_27_23F008)
    C1(8, 0xD8, fn_27_23FF58)
    C1(9, 0x54, fn_27_241404)
    C1(10, 0x54, fn_27_2418F4)
    C1(11, 0x64, fn_27_2407E0)
    case 12: { void* p = __nw__FUlQ25Heaps8HeapType(0x6C, 2); if (p) p = fn_27_23EB70(p, 2); return p; }
    C1(13, 0xE4, fn_27_23AC74)
    C1(14, 0xD4, fn_27_240538)
    C1(15, 0x54, fn_27_241850)
    C1(16, 0x54, fn_27_2416C0)
    C1(17, 0x64, fn_27_240F70)
    C1(18, 0x6C, fn_27_240B14)
    C1(19, 0x74, fn_27_241B14)
    C1(20, 0x68, fn_27_24113C)
    }
    return 0;
}
