#pragma force_active on
// fn_104_6280 destroys the embedded member whose storage begins at +0x1FC of
// the passed object (via fn_27_1A15B8 with flag -1, never freeing the member
// independently), then runs the object's own cleanup fn_104_62F8 with flag 0,
// and only a positive deleting flag releases the allocation through
// operator delete. The pointer is returned in every case.
void operator delete(void*);
extern "C" void fn_27_1A15B8(void*, short);
extern "C" void fn_104_62F8(void*, short);

extern "C" void* fn_104_6280(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x1FC, -1);
        if (object != 0) {
            fn_104_62F8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
