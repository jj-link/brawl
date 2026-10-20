#pragma force_active on
// fn_96_1245C destroys the Kirby embedded member whose storage begins at
// +0x204 of the passed object and then applies the outer object's own
// cleanup chain, mirroring the published reverse-construction destructor
// which invokes this unit as fn_96_1245C(storage, -1) while unwinding its
// embedded members.
//
// The embedded member's own cleanup is fn_96_123FC (destroy its +0 member
// with flag -1, then honor its deleting flag), called here with -1 so the
// embedded storage is never freed independently. The outer object's
// memberless cleanup fn_96_122C8 runs with flag 0, and only a positive
// deleting flag releases the outer allocation itself. The pointer is
// returned in every case.
void operator delete(void*);
extern "C" void* fn_96_123FC(void* object, short deleting);
extern "C" void* fn_96_122C8(void* object, short deleting);

extern "C" void* fn_96_1245C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_123FC(storage + 0x204, -1);
        if (object != 0) {
            fn_96_122C8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
