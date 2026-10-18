#pragma force_active on
extern "C" {
void operator delete(void* p);

void* fn_110_3A60(void* p, short n) {
    if (p != 0) {
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
