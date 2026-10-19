#pragma force_active on
extern "C" {
void* fn_123_FD34(void* p, short flags);
void operator delete(void* p);

void* fn_123_FCC8(void* p, short flags) {
    if (p != 0) {
        fn_123_FD34(p, 0);
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
