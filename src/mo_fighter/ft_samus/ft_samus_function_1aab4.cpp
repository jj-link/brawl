#pragma force_active on
extern "C" {
void operator delete(void* p);

void* fn_94_1AAB4(void* p, short flags) {
    if (p != 0 && flags > 0) {
        operator delete(p);
    }
    return p;
}
}
