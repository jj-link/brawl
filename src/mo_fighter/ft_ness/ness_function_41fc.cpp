#pragma force_active on
void operator delete(void*);

extern "C" void* fn_101_425C(void*, short);

extern "C" void* fn_101_41FC(void* object, short deleting) {
    if (object != 0) {
        fn_101_425C(static_cast<unsigned char*>(object) + 0x0C,
                    static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
