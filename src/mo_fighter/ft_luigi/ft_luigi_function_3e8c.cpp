#pragma force_active on
extern "C" void* fn_99_3EEC(void*, short);

extern "C" void* fn_99_3E8C(void* object, short deleting) {
    if (object) {
        int destroyMember = -1;
        fn_99_3EEC(static_cast<unsigned char*>(object) + 0x0C, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
