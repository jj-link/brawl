#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_40_A4(void*);

extern "C" void* fn_40_70()
{
    void* object = __nw__FUlQ25Heaps8HeapType(0x630, 0xF);
    if (object) {
        object = fn_40_A4(object);
    }
    return object;
}
