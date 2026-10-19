#pragma force_active on
extern "C" void* fn_123_1A8C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_1A30(void* object, short deleting) {
    void* result;
    if (object != 0) {
        short memberDeleting = 0;
        result = fn_123_1A8C(object, memberDeleting);
        if (deleting > 0) {
            result = object;
            __dl__FPv(object);
        }
    }
    return object;
}
