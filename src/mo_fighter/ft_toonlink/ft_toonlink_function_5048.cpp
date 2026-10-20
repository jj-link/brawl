#pragma force_active on
// fn_121_5048 mirrors the published reverse-construction destructor pattern:
// the embedded member whose storage begins at +0x318 of the passed object is
// destroyed through fn_27_D2904 with flag -1 (never freed independently),
// then the outer object's own cleanup fn_121_4FD0 runs with flag 0, and only
// a positive deleting flag releases the outer allocation itself. The pointer
// is returned in every case.

void operator delete(void*);
extern "C" void fn_27_D2904(void* member, short deleteFlag);
extern "C" void fn_121_4FD0(void* object, short deleting);

extern "C" void* fn_121_5048(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_D2904(storage + 0x318, -1);
        if (object != 0) {
            fn_121_4FD0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
