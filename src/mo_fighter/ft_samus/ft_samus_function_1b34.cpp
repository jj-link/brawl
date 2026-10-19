#pragma force_active on
typedef signed short s16;

void operator delete(void* p);
extern "C" void fn_94_1AD0(void* self, s16 v);

extern "C" void* fn_94_1B34(void* p, s16 flags) {
    if (p != 0) {
        fn_94_1AD0(p, 0);
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}
