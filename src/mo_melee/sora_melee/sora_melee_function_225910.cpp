#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_27_225A14(void*);
extern "C" void loadPositionData__11stPositionsFPQ34nw4r3g3d7ResFile(void*, void*);

extern "C" void* fn_27_225910(void** arg) {
    void* data;
    void* obj = __nw__FUlQ25Heaps8HeapType(0x64, 0xf);
    if (obj) {
        char* p = (char*)obj;
        *(void**)(p + 0) = 0;
        data = *arg;
        *(unsigned char*)(p + 4) = 1;
        *(void**)(p + 8) = data;
        *(int*)(p + 0x50) = 0;
        *(unsigned char*)(p + 0x62) = 0;
        *(void**)p = __nw__FUlQ25Heaps8HeapType(0xEC, 0xf);
        fn_27_225A14(obj);
        void* resFile = data;
        loadPositionData__11stPositionsFPQ34nw4r3g3d7ResFile(obj, &resFile);
    }
    return obj;
}
