#pragma force_active on
extern "C" void* fn_27_1A2B08(void*, short);

extern "C" void* fn_99_3E2C(void* object, short deleting) {
    if (object) {
        int destroyMember = -1;
        fn_27_1A2B08(static_cast<unsigned char*>(object) + 4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
