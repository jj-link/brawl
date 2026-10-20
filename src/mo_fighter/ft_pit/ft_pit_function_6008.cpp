#pragma force_active on
// fn_112_6008 mirrors the reverse-construction destructor pattern used
// throughout ft modules: destroy the embedded member stored at +0x2D0 of the
// passed object via fn_27_1A1B88 (with delete flag -1), then run the outer
// object's own cleanup fn_112_6080 with flag 0, and only a positive deleting
// flag releases the outer allocation through operator delete. The pointer is
// returned in every case.
void operator delete(void*);

extern "C" void fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_112_6080(void* object, short deleting);

extern "C" void* fn_112_6008(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x2D0, -1);
        if (object != 0) {
            fn_112_6080(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
