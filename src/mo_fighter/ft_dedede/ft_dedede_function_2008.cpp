#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_208C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_117_2944(void*, short);
}

// Guarded destructor for the Dedede fighter module: destroys embedded members,
// runs the base destructor layer non-deleting, and frees storage if requested.
extern "C" void* fn_117_2008(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_117_208C(static_cast<unsigned char*>(object) + 0x45984, memberDeleting);
        fn_27_C74E8(static_cast<unsigned char*>(object) + 0x45974, memberDeleting);
        fn_117_2944(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
