#pragma force_active on
void operator delete(void*);

extern "C" void* fn_123_10598(void* p, short flags) {
    if (p != 0 && flags > 0) {
        operator delete(p);
    }
    return p;
}
