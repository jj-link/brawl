#pragma force_active on
extern "C" void* fn_27_5AE44(void*, short);

extern "C" {
void* fn_113_2CD10(void* p, short flags) {
    if (p != 0) {
        fn_27_5AE44(p, -1);
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
