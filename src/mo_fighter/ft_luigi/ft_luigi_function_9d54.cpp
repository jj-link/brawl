#pragma force_active on
extern "C" void* fn_99_9CF4(void*, short);

extern "C" void* fn_99_9D54(void* object, short deleting) {
    if (object) {
        int destroyMember = -1;
        fn_99_9CF4(static_cast<unsigned char*>(object) + 4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
