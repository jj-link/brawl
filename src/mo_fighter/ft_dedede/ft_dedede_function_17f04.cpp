// fn_117_17F04 destroys the Dedede embedded member whose storage begins at
// +0xD4 of the passed object and then applies the outer object's own cleanup
// chain, mirroring the published reverse-construction destructor
// fn_117_1F234, which invokes this unit as
// fn_117_17F04(storage + 0x2650, -1) while unwinding its embedded members.
//
// The embedded member's own cleanup is fn_117_17F7C (destroy its +0 member
// through fn_117_17FD8 with flag 0, then honor its deleting flag), called
// here with -1 so the embedded storage is never freed independently. The
// outer object's memberless cleanup fn_117_17A6C runs with flag 0, and only
// a positive deleting flag releases the outer allocation itself. The pointer
// is returned in every case.
void operator delete(void*);
extern "C" void fn_117_17F7C(void* object, short deleting);
extern "C" void* fn_117_17A6C(void* object, short deleting);

extern "C" void* fn_117_17F04(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_17F7C(storage + 0xD4, -1);
        if (object != 0) {
            fn_117_17A6C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
