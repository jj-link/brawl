#pragma force_active on
void operator delete(void*);

extern "C" {
void fn_27_614C4(void*, short);
void* fn_27_D3080(void*, short);
}

// Complete-object destructor for the fighter-module member at +0xAC.
// Destroys the embedded member via its sora_melee destructor, then the
// object itself behind its own null guard (the guard is preserved verbatim
// from the original), and finally releases the storage when the deleting
// form was requested.
extern "C" void* fn_117_59E0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_614C4(members + 0xAC, memberDeleting);
        if (object != 0) {
            fn_27_D3080(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
