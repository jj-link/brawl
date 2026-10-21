#pragma force_active on
typedef unsigned int u32;

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_2_385C0(unsigned char*);
void* fn_2_38800(void*, void*, void*, void*, void*, void*, void*, void*);
}

extern "C" void* fn_2_38530(void* a, void* b, void* c, void* d, void* e, void* f, void* g) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x1F4, 0x2A);
    if (obj)
        obj = fn_2_385C0((unsigned char*)obj);
    fn_2_38800(obj, a, b, c, d, e, f, g);
    return obj;
}
