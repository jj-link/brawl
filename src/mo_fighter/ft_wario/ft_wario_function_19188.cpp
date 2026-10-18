#pragma force_active on
extern "C" {
void* fn_110_19188(void* p, short flag) {
    if (p) {
        if (flag > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
}
