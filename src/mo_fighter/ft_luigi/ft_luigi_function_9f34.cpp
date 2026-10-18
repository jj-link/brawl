#pragma force_active on
extern "C" void* fn_99_9ED8(void*, short);

extern "C" void* fn_99_9F34(void* object, short deleting) {
    if (object) {
        int destroyMember = -1;
        fn_99_9ED8(static_cast<unsigned char*>(object) + 0x4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
