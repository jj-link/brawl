#pragma force_active on
extern "C" void* fn_99_9D54(void*, short);

extern "C" void* fn_99_9DB4(void* object, short deleting) {
    if (object) {
        int destroyMember = -1;
        fn_99_9D54(static_cast<unsigned char*>(object) + 0x8, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
