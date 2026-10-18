#pragma force_active on
void operator delete(void* p);

extern "C" void* fn_71_9D30(void* p, int n) {
    if (p != 0) {
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
