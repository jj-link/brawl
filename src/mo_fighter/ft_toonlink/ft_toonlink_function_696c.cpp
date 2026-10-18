#pragma force_active on
extern "C" void operator delete(void* p);

extern "C" void* fn_121_696C(void* p, short n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
