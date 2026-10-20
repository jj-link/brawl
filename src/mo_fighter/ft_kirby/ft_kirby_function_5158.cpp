#pragma force_active on
// fn_96_5158 destroys the Kirby embedded member whose storage begins at
// +0xF0 of the passed object and then applies the outer object's own
// cleanup chain, mirroring the published reverse-construction destructor
// pattern. The embedded member's cleanup fn_96_50E0 is called with flag 0
// so the embedded storage is never freed independently, and only a
// positive deleting flag releases the outer allocation itself. The
// pointer is returned in every case.
void operator delete(void*);
extern "C" void fn_96_50E0(void* object, short deleting);
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);

extern "C" void* fn_96_5158(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1B88(storage + 0xF0, -1);
        if (object != 0) {
            fn_96_50E0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
