#pragma force_active on

// fn_122_3320 tears down a Snake fighter allocation: it destroys the
// embedded member living at +0x22068 through fn_122_339C with flag -1 so
// that storage is never freed on its own, runs the outer object's own
// cleanup fn_122_4E44 with flag 0, and only releases the allocation itself
// when the deleting flag is positive. The pointer is returned in every case.
extern "C" void* fn_122_339C(void* object, short deleting);
extern "C" void fn_122_4E44(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_3320(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_339C(storage + 0x22068, -1);
        if (object != 0) {
            fn_122_4E44(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
