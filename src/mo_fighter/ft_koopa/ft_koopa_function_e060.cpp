#pragma force_active on
extern "C" {
void operator delete(void* p);

void* fn_102_E060(void* p, short flags) {
    if (p != 0) {
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
