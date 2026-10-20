#pragma force_active on
// fn_105_69B4 destroys the Ice Climber embedded member whose storage begins
// at +0x244 of the passed object and then applies the outer object's own
// cleanup chain. The embedded member's cleanup fn_105_6A2C is called with
// flag 0 (never freeing the embedded storage independently), the outer
// object's memberless cleanup fn_27_1A1FE4 runs with flag -1, and only a
// positive deleting flag releases the outer allocation itself. The pointer
// is returned in every case.

void operator delete(void*);
extern "C" void* fn_105_6A2C(void* object, short deleting);
extern "C" void* fn_27_1A1FE4(void* object, short deleting);

extern "C" void* fn_105_69B4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1FE4(storage + 0x244, -1);
        if (object != 0) {
            fn_105_6A2C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
