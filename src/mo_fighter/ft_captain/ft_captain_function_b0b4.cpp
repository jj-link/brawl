#pragma force_active on
extern "C" void* fn_100_B054(void* object, short flag);
extern "C" void* fn_100_AF1C(void* object, short flag);
extern "C" void __dl__FPv(void*);

// Tear down a Captain event-management slot: release any held article
// resources, drop the managed instance, and optionally free the header.
extern "C" void* fn_100_B0B4(void* object, short flag) {
    if (object) {
        fn_100_B054(static_cast<char*>(object) + 0xEC, -1);
        if (object)
            fn_100_AF1C(object, 0);
        if (flag > 0)
            __dl__FPv(object);
    }
    return object;
}
