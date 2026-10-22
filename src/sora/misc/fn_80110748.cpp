#pragma force_active on
typedef unsigned long u32;

extern "C" void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, u32);
extern "C" void fn_80112EBC(void*, void*, u32);

extern "C" void* fn_80110748(void* arg0, u32 arg1, u32 arg2)
{
    void* base = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(15, arg1 * 0x60);
    void* p = base;
    u32 i = 0;
    u32 off = arg2;
    while (i < arg1) {
        if (p != 0) {
            fn_80112EBC(p, arg0, off);
        }
        p = (char*)p + 0x60;
        off += 0x6C;
        i++;
    }
    return base;
}
