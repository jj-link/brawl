#pragma force_active on

// fn_122_656C is the reverse-construction destructor for the Snake embedded
// object whose storage begins at +0x14650 of the outer allocation. It first
// destroys the embedded member through fn_122_65E8 with the non-deleting
// flag (-1), then runs the outer object's own memberless cleanup
// fn_122_6BE8 with flag 0, and finally releases the outer allocation with
// operator delete only when the deleting flag is positive. The original
// pointer is returned in every case.
extern "C" void fn_122_65E8(void* object, short deleting);
extern "C" void fn_122_6BE8(void* object, short deleting);
extern "C" void operator delete(void*);

extern "C" void* fn_122_656C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_65E8(storage + 0x14650, -1);
        if (object != 0) {
            fn_122_6BE8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
