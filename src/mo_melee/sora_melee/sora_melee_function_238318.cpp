#pragma force_active on
extern "C" void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* __construct_new_array(void*, void (*)(), void*, unsigned long, int);
extern "C" unsigned int fn_80196B1C(void*);
extern "C" unsigned int fn_80196CD0(void*, void*);
extern "C" unsigned int fn_80196DFC(void*);
extern "C" void fn_27_238310();
extern "C" void fn_27_238314();
extern "C" void* memset(void*, int, unsigned long);

extern "C" void fn_27_238318(void* self, void** arg1) {
    int countA, countB, countC, countD;
    countD = fn_80196DFC(arg1);
    countC = *(unsigned short*)((char*)*arg1 + 0x32);
    countB = fn_80196CD0(arg1, *arg1);
    countA = fn_80196B1C(arg1);
    *(unsigned int*)((char*)self + 4) = countA;
    *(void**)((char*)self + 0x14) = __nwa__FUlQ25Heaps8HeapType(countA * 0x14, 0x11);
    *(unsigned int*)((char*)self + 8) = countB;
    *(void**)((char*)self + 0x18) = __construct_new_array(__nwa__FUlQ25Heaps8HeapType(countB * 0x2c + 0x10, 0x11), fn_27_238310, 0, 0x2c, countB);
    *(unsigned int*)((char*)self + 0xc) = countC;
    *(void**)((char*)self + 0x1c) = __construct_new_array(__nwa__FUlQ25Heaps8HeapType(countC * 0x20 + 0x10, 0x11), fn_27_238314, 0, 0x20, countC);
    *(unsigned int*)((char*)self + 0x10) = countD;
    *(void**)((char*)self + 0x20) = __nwa__FUlQ25Heaps8HeapType(countD * 0x2c, 0x11);
    memset(*(void**)((char*)self + 0x14), 0, (unsigned int)countA * 0x14);
    memset(*(void**)((char*)self + 0x18), 0, (unsigned int)countB * 0x2c);
    memset(*(void**)((char*)self + 0x1c), 0, (unsigned int)countC * 0x20);
    memset(*(void**)((char*)self + 0x20), 0, (unsigned int)countD * 0x2c);
}