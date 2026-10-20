#pragma force_active on
// fn_93_4F58 is the reverse-construction destructor for the ft_link object.
// It destroys the embedded member whose storage begins at +0x2D0 of the
// passed object (via fn_27_1A1B88 with flag -1 so the embedded storage is
// never freed independently), then runs the object's own memberless cleanup
// fn_93_4EE0 with flag 0, and only a positive deleting flag releases the
// outer allocation itself via operator delete. The pointer is returned in
// every case.

void operator delete(void*);
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_93_4EE0(void* object, short deleting);

extern "C" void* fn_93_4F58(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1B88(storage + 0x2D0, -1);
        if (object != 0) {
            fn_93_4EE0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
