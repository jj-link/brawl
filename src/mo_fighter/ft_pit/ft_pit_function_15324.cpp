#pragma force_active on
extern "C" void fn_112_5480(void* object, short deleting);
extern "C" void fn_112_15394(void* object, short deleting);

extern "C" {
void* fn_112_15324(void* object, short deleting);
}

void* fn_112_15324(void* object, short deleting) {
    if (object != 0) {
        fn_112_5480(static_cast<unsigned char*>(object) + 0x13D48, static_cast<short>(-1));
        fn_112_15394(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
