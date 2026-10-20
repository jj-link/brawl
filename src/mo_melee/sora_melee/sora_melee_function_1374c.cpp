#pragma force_active on
extern "C" void __dt__9soAnimChrFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1374C(void* p, int flag) {
    if (p != 0) {
        __dt__9soAnimChrFv((char*)p + 0x20, -1);
        __dt__9soAnimChrFv(p, -1);
        if (flag > 0)
            __dl__FPv(p);
    }
    return p;
}
