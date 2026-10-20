#pragma force_active on
// fn_94_5458 destroys the embedded member whose storage begins at +0x318 of
// the passed object, then applies the outer object's own cleanup fn_94_54D0.
//
// The embedded member's cleanup is fn_27_D2904, called here with -1 so the
// embedded storage is never freed independently. The outer cleanup runs with
// flag 0, and only a positive deleting flag releases the outer allocation
// itself via operator delete. The pointer is returned in every case.
void operator delete(void*);
extern "C" void* fn_27_D2904(void* member, short deleteFlag);
extern "C" void* fn_94_54D0(void* object, short deleting);

extern "C" void* fn_94_5458(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_D2904(storage + 0x318, -1);
        if (object != 0) {
            fn_94_54D0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
