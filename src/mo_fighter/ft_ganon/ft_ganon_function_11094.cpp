#pragma force_active on
extern "C" {

void __dl__FPv(void*);

void* fn_109_11094(void* p, short s) {
    if (p != 0 && s > 0) {
        __dl__FPv(p);
    }
    return p;
}

}
