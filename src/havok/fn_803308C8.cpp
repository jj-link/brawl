#pragma force_active on
extern "C" void __dt__14Class_8027D01CFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_803308C8(void* arg0, int arg1) {
    if (arg0) {
        void* sub = (char*)arg0 + 0xC;
        if (sub) {
            __dt__14Class_8027D01CFv(sub, -1);
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
