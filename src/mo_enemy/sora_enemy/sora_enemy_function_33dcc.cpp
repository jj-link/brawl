#pragma force_active on
typedef signed short s16;

extern "C" {
void* fn_41_33DCC(void* p, s16 flag) {
    if (p != 0 && flag > 0) {
        operator delete(p);
    }
    return p;
}
}
