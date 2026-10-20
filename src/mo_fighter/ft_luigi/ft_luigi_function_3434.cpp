#pragma force_active on
extern "C" void* fn_99_34F8(void*, short);

extern "C" void* fn_99_3434(void* object, short deleting) {
    if (object) {
        int destroyMember = -1;
        if (object) fn_99_34F8(static_cast<unsigned char*>(object) + 4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
