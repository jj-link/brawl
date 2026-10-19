#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_101_5308(void*, short);
void* fn_101_5E34(void*, short);
}

extern "C" void* fn_101_528C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_101_5308(members + 0x20490, static_cast<short>(-1));

        if (object != 0) {
            fn_101_5E34(object, static_cast<short>(0));
        }

        if (deleting > 0) {
            operator delete(object);
        }
    }

    return object;
}
