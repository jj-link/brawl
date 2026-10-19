#pragma force_active on
extern "C" void* fn_107_3548(void*, short);
extern "C" void fn_107_4AA0(void*, short);

extern "C" void* fn_107_34D8(void* object, short deleting) {
    if (object != 0) {
        fn_107_3548(static_cast<unsigned char*>(object) + 0x86C8, static_cast<short>(-1));
        fn_107_4AA0(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
