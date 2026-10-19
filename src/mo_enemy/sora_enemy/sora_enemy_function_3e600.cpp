#pragma force_active on
extern "C" void fn_41_3E534(void*, short);

extern "C" void* fn_41_3E600(void* p, short flags) {
    if (p != 0) {
        if (p != 0) {
            fn_41_3E534(static_cast<char*>(p) + 4, -1);
        }
        if (flags > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
