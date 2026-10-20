#pragma force_active on
// fn_125_6720 destroys the Wolf embedded member whose storage begins at
// +0x4B8 of the passed object and then applies the outer object's own
// cleanup chain. The embedded member's own cleanup is fn_125_6798, called
// with flag 0 so the embedded storage is never freed independently. Only a
// positive deleting flag releases the outer allocation itself. The pointer
// is returned in every case.

void operator delete(void*);
extern "C" void fn_125_6798(void* object, short deleting);
extern "C" void* fn_27_1A1E70(void* object, short value);

extern "C" void* fn_125_6720(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1E70(storage + 0x4B8, -1);
        if (object != 0) {
            fn_125_6798(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
