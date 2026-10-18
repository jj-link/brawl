#pragma force_active on
extern "C" void* fn_99_35B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_3558(void* object, short deleting) {
    if (object) {
        short destroyMember = -1;
        fn_99_35B8(static_cast<unsigned char*>(object) + 4, destroyMember);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
