#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_80152B5C(void*, int);
extern "C" void fn_8004B23C(void*, void**, int*);
extern "C" void* getInstance__8ipSwitchFv(void);
extern "C" void fn_80152C4C(void*, void*, void*);
extern "C" int fn_800F18C4(void*, void*, int, int, int, void*, int, int, int, int);

extern "C" int fn_800DCF74(char* self) {
    void* obj;
    void* p14;
    void* p10;
    if (*(int*)(self + 0x9C) != 0) {
        return 0;
    }
    obj = __nw__FUlQ25Heaps8HeapType(0x14, 0x2A);
    if (obj != 0) {
        obj = fn_80152B5C(obj, 0x2A);
    }
    *(void**)(self + 0xB8) = obj;
    fn_8004B23C(*(void**)((char*)getInstance__8ipSwitchFv() + 0x18), &p14, (int*)&p10);
    fn_80152C4C(*(void**)(self + 0xB8), p14, p10);
    *(int*)(self + 0x9C) = fn_800F18C4(self + 0x30, self + 0x3C, *(int*)(self + 0x90), *(int*)(self + 0x8), 0x60, *(void**)(self + 0xB8), 0, 0x2A, 0x2A, 0x2A);
    return 1;
}
