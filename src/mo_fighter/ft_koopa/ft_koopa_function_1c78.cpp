#pragma force_active on
extern "C" {
void fn_102_1AA4(void*, short);
void operator delete(void*);

void* fn_102_1C78(void* p, short flag) {
    if (p != 0) {
        fn_102_1AA4(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
