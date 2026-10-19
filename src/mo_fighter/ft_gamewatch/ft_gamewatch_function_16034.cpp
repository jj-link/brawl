#pragma force_active on
extern "C" void* fn_107_4554(void*, short);

extern "C" {
void* fn_107_16034(void* p, short n) {
    if (p) {
        fn_107_4554(p, 0);
        if (n > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
}
