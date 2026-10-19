#pragma force_active on
extern "C" void* fn_107_1F06C(void* ptr, short flag);

void operator delete(void* p);

extern "C" void* fn_107_1F0AC(void* p, short flag) {
    if (p != 0) {
        fn_107_1F06C(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
