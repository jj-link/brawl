#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_102_1990(void* object, short deleting);
void* fn_102_1D70(void* object, short deleting);
void* fn_102_1E0C(void* object, short deleting);
void* fn_102_10DE0(void* object, short deleting);
void* fn_27_125E20(void* object, short deleting);
}

// Destroy the Koopa fighter storage: tear down the embedded subobjects
// (at +0x13E68, +0x139B0, +0x13974, +0x194) with the deleting form,
// notify fn_27_125E20 non-deletingly, and free the storage when a
// delete was requested, preserving the original pointer either way.
extern "C" void* fn_102_10D40(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_102_1990(members + 0x13E68, memberDeleting);
        fn_102_1D70(members + 0x139B0, memberDeleting);
        fn_102_1E0C(members + 0x13974, memberDeleting);
        fn_102_10DE0(members + 0x194, memberDeleting);
        fn_27_125E20(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
