#pragma force_active on
extern "C" void fn_27_66114(void*, short);

extern "C" {
void* fn_122_9F38(void* p, short flags) {
    if (p != 0) {
        fn_27_66114(p, static_cast<short>(-1));
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
