#pragma force_active on
void operator delete(void* p);

extern "C" void* fn_105_15E00(void* p, short flag) {
    if (p != 0) {
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
