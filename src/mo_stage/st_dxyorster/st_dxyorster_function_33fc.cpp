#pragma force_active on
extern "C" void* fn_76_33BC(void* p, int n);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

struct StDxyOrster {
    char pad[0xc];
};

extern "C" void* fn_76_33FC(StDxyOrster* p, int n) {
    if (p) {
        __destroy_arr((char*)p + 0xc, (void (*)(void*, int))fn_76_33BC, 8, 6);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
