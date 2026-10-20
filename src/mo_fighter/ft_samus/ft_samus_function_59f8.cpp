#pragma force_active on
// fn_94_59F8: Samus's embedded-member teardown.  The member whose storage
// begins at +0x88 of the passed object is destroyed first (flag -1, so it is
// never freed on its own), then the object's own memberless cleanup
// fn_94_5A70 runs with flag 0, and only a positive deleting flag releases the
// outer allocation itself.  The pointer is returned in every case.
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void* fn_94_5A70(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_59F8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x88, -1);
        if (object != 0) {
            fn_94_5A70(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
