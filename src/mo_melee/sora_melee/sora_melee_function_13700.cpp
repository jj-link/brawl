#pragma force_active on
extern "C" void __ct__9soAnimChrFv(void*);

extern "C" void* fn_27_13700(void* p) {
    __ct__9soAnimChrFv(p);
    *(int*)((char*)p + 0x1C) = -1;
    __ct__9soAnimChrFv((char*)p + 0x20);
    *(int*)((char*)p + 0x3C) = -1;
    return p;
}
