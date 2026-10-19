#pragma force_active on
extern "C" void* fn_27_C31CC(void*, short);

void operator delete(void* p);

extern "C" void* fn_121_13294(void* p, short flags) {
    if (p != 0) {
        fn_27_C31CC(p, -1);
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}
