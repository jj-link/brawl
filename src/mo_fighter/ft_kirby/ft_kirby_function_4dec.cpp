#pragma force_active on
void operator delete(void* p);

extern "C" void* fn_96_4DEC(void* p, short flags) {
    if (p != 0) {
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}
