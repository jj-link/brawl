#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_85_A4(char*);

void* fn_85_5520() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x1c94, 0xf);
    if (p) {
        p = fn_85_A4((char*)p);
    }
    return p;
}
}
