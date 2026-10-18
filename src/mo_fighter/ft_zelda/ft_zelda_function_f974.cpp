#pragma force_active on
extern "C" {
void operator delete(void* p);

void* fn_104_F974(void* p, short n) {
    if (p != 0 && n > 0) {
        operator delete(p);
    }
    return p;
}
}
