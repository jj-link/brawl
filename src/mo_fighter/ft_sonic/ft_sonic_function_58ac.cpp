#pragma force_active on
// fn_123_58AC destroys the embedded member whose storage begins at +0x1FC of
// the passed object (through fn_27_1A15B8 with flag -1, so that storage is
// never freed independently), then applies the outer object's own cleanup
// chain fn_123_5924 with flag 0, and only a positive deleting flag releases
// the outer allocation itself. The pointer is returned in every case.

void operator delete(void*);
extern "C" void fn_27_1A15B8(void*, short);
extern "C" void fn_123_5924(void*, short);

extern "C" void* fn_123_58AC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x1fc, -1);
        if (object != 0) {
            fn_123_5924(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
