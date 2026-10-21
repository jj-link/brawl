#pragma force_active on
extern "C" {
void fn_10_14414(void* a, const char* name, int flag, void* b, void* c);
void* fn_800FD650(void* obj, void* arg, int flag);
void fn_800FD728(void* a, void* b, void* c);
void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
extern const char lbl_10_rodata_690[];
void fn_10_14380(void* a, void* b, void* c);
}

void fn_10_14380(void* a, void* b, void* c) {
    fn_10_14414(a, lbl_10_rodata_690, 3, b, c);
    void* arg = *(void**)((char*)a + 0x1b0);
    void* obj = __nw__FUlQ25Heaps8HeapType(0x20, 0x2a);
    if (obj != 0) {
        obj = fn_800FD650(obj, arg, 1);
    }
    *(void**)((char*)a + 0x41c) = obj;
    fn_800FD728(obj, b, c);
}
