#pragma force_active on
extern "C" void* fn_27_C31CC(void*, short);

extern "C" {
void* fn_123_12980(void* p, short flag) {
    if (p != 0) {
        fn_27_C31CC(p, -1);
        if (flag > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
}
