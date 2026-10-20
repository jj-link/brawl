// fn_93_D848 mirrors the published reverse-construction destructor pattern:
// the embedded member at +0x1C8 is destroyed through fn_93_D7E8 with a
// deleting flag of -1 (embedded storage never freed independently), then the
// outer object's memberless cleanup fn_93_D6B4 runs with flag 0, and only a
// positive deleting flag releases the outer allocation via operator delete.
// The pointer is returned in every case.
#pragma force_active on

extern "C" void fn_93_D7E8(void* object, short deleting);
extern "C" void fn_93_D6B4(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_D848(void* object, short deleting) {
    if (object != 0) {
        fn_93_D7E8(static_cast<unsigned char*>(object) + 0x1C8, -1);
        if (object != 0) {
            fn_93_D6B4(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
