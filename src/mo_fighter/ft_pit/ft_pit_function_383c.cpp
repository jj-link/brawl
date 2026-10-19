#pragma force_active on
extern "C" void* fn_112_3898(void* p, short size);

extern "C" void* fn_112_383C(void* p, short size) {
    if (p != 0) {
        fn_112_3898(p, 0);
        if (size > 0) {
            operator delete(p);
        }
    }
    return p;
}
