#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_800800D8(void*);
extern "C" void fn_80080118(void*, int);

extern "C" void* fn_800966EC(void* self, int arg) {
    void* p;
    *(unsigned char*)((char*)self + 0x0) = 1;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xC) = 0;
    *(unsigned int*)((char*)self + 0x10) = 0x80000000;
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x18) = 0;
    *(unsigned int*)((char*)self + 0x1C) = 0x80000000;
    p = __nw__FUlQ25Heaps8HeapType(0x40, 0xD);
    if (p != 0) {
        p = fn_800800D8(p);
    }
    *(void**)((char*)self + 0x4) = p;
    fn_80080118(p, arg);
    return self;
}
