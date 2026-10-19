#pragma force_active on
extern "C" {
void fn_73_2CC8(void*, int);
}

extern "C" {
void* fn_73_DC78(void* p, int size) {
    if (p != 0) {
        fn_73_2CC8(p, 0);
        if (size > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
}
