#pragma force_active on
extern "C" {
void* fn_123_107F0(void* p, short flags);
}

extern "C" void* fn_123_107F0(void* p, short flags) {
    if (p != 0 && flags > 0) {
        operator delete(p);
    }
    return p;
}
