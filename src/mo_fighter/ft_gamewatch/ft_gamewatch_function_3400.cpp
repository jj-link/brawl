#pragma force_active on
typedef short s16;

extern "C" {
void* fn_107_345C(void* object, s16 deleting);
void __dl__FPv(void* ptr);
void* fn_107_3400(void* object, s16 deleting) {
    if (object != 0) {
        fn_107_345C(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
