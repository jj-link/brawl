#pragma force_active on
extern "C" {
void __dt__10grYakumonoFv(void* self, int flags);
void __dl__FPv(void* p);
}

extern "C" void* fn_67_20BC(void* p, int flags) {
    if (p != 0) {
        __dt__10grYakumonoFv(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
