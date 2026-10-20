#pragma force_active on
// fn_126_34E8 mirrors the published destructor pattern: the embedded member
// at +0x4B8 of the passed object is destroyed through fn_27_1A1E70 with
// flag -1 (so the embedded storage is never freed independently), then the
// object's own memberless cleanup fn_126_3560 runs with flag 0, and only a
// positive deleting flag releases the outer allocation via operator delete.
// The pointer is returned in every case.
void operator delete(void*);
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_126_3560(void*, short);

extern "C" void* fn_126_34E8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1E70(storage + 0x4B8, static_cast<short>(-1));
        if (object != 0) {
            fn_126_3560(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
