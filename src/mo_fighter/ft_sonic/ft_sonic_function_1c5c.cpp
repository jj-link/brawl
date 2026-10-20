#pragma force_active on
extern "C" {
void* fn_123_1A8C(void*, short);

void* fn_123_1C5C(void* object, short memberDeleting) {
    if (object != 0) {
        fn_123_1A8C(object, 0);
        if (memberDeleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}
