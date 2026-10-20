#pragma force_active on
// fn_120_45E8 destroys the embedded member whose storage begins at +0x11C of
// the passed object and then applies the outer object's own cleanup chain.
// The embedded member's cleanup fn_120_4660 is invoked with flag 0 so the
// embedded storage is never freed independently; only a positive deleting
// flag releases the outer allocation itself. The pointer is returned.
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_120_4660(void* object, short deleting);

extern "C" void* fn_120_45E8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x11C, -1);
        if (object != 0) {
            fn_120_4660(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
