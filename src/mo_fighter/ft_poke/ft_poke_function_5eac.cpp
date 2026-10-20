#pragma force_active on
// fn_116_5EAC is the deleting destructor for a fighter whose embedded member
// storage begins at +0x11C of the passed object. The member's own cleanup is
// fn_27_1A15B8, called here with -1 so the embedded storage is never freed
// independently. The outer object's cleanup fn_116_5F24 runs with flag 0,
// and only a positive deleting flag releases the outer allocation itself.
// The pointer is returned in every case.
void operator delete(void*);
extern "C" void fn_27_1A15B8(void* storage, short deleting);
extern "C" void* fn_116_5F24(void* object, short deleting);

extern "C" void* fn_116_5EAC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x11C, -1);
        if (object != 0) {
            fn_116_5F24(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
