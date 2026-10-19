#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void* fn_109_41F0(void*, short);

void* fn_109_10D90(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = 0;
        fn_109_41F0(object, baseDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
