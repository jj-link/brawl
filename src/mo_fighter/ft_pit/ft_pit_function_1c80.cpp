#pragma force_active on
extern "C" {
void fn_112_1B64(void* self, short p);
}

extern "C" void* fn_112_1C80(void* p, short flag) {
    if (p != 0) {
        fn_112_1B64(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
