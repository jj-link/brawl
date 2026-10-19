#pragma force_active on
extern "C" {
void __dl__FPv(void* p);

void* fn_27_82444(void* p, int size) {
    if (p != 0) {
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
