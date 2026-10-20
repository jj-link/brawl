#pragma force_active on
extern "C" void* fn_93_482C(void* p, short size);
void operator delete(void* p);

extern "C" void* fn_93_486C(void* p, short size) {
    if (p != 0) {
        fn_93_482C(p, 0);
        if (size > 0) {
            operator delete(p);
        }
    }
    return p;
}
