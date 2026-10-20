#pragma force_active on
// fn_96_57E8 destroys the member whose storage begins at +0x4B8 of the passed
// object (through fn_27_1A1E70 with flag -1), then applies the object's own
// cleanup chain with fn_96_5770 using flag 0, and only a positive deleting flag
// releases the object itself. The pointer is returned in every case.

extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void fn_96_5770(void*, short);

void operator delete(void*);

extern "C" void* fn_96_57E8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<char*>(object) + 0x4B8, -1);
        if (object != 0) {
            fn_96_5770(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
