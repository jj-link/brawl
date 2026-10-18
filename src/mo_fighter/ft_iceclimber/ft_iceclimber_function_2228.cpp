#pragma force_active on
extern "C" {

void __dl__FPv(void*);

void* fn_105_2228(void* p, short v) {
    if (p != 0 && v > 0) {
        __dl__FPv(p);
    }
    return p;
}

}
