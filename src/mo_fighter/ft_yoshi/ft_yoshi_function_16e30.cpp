#pragma force_active on
extern "C" {
void* fn_95_16E30(void* p, short flag) {
    if (p != 0 && flag > 0) {
        operator delete(p);
    }
    return p;
}
}
