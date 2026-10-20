#pragma force_active on
// fn_123_5A14 destroys the Sonic embedded member whose storage begins at
// +0x138 of the passed object (via fn_27_1A15B8 with flag -1) and then
// applies the outer object's own cleanup chain via fn_123_5A8C with flag 0.
// Only a positive deleting flag releases the outer allocation itself
// through __dl__FPv. The pointer is returned in every case.
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_123_5A8C(void* object, short deleting);

extern "C" void* fn_123_5A14(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x138, -1);
        if (object != 0) {
            fn_123_5A8C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
