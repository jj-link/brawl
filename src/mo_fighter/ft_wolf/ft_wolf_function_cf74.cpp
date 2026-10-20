#pragma force_active on
// fn_125_CF74: reverse-construction destructor for the Wolf embedded member.
// Calls fn_125_CF14 on storage +0xEC with flag -1, then fn_125_CDDC on the
// outer object with flag 0, and deletes the outer allocation when the
// deleting flag is positive. Returns the outer object pointer.

void operator delete(void*);
extern "C" void fn_125_CF14(void* object, short deleting);
extern "C" void fn_125_CDDC(void* object, short deleting);

extern "C" void* fn_125_CF74(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_125_CF14(storage + 0xEC, -1);
        if (object != 0) {
            fn_125_CDDC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
