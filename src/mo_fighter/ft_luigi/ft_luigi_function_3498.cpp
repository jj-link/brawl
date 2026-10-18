#pragma force_active on
extern "C" void* fn_99_34F8(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_99_3498(void* object, short deleting) {
    if (object) {
        int destroyMember = -1;
        fn_99_34F8(static_cast<unsigned char*>(object) + 4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
