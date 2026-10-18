#pragma force_active on
extern "C" {
void operator delete(void* p);
void* fn_112_69C0(void* p, short n);
}

extern "C" void* fn_112_69C0(void* p, short n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
