#pragma force_active on
extern "C" {
void* fn_94_4BB4(void* p, short n) {
    if (p && n > 0) {
        ::operator delete(p);
    }
    return p;
}
}
