#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_9_80(void* self, void* arg);
void* fn_9_438(void* obj, void* a, void* b);
}

extern "C" void* fn_9_0(void* a, void* b, void* c) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x17f4, 0x2a);
    void* ret = obj;
    if (obj != 0) {
        ret = fn_9_80(obj, c);
    }
    fn_9_438(ret, a, b);
    return ret;
}
