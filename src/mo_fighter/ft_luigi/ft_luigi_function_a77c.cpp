#pragma force_active on
extern "C" void* fn_99_A71C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_A77C(void* object, short deleting) {
    if (object) {
        short destroyMember = -1;
        fn_99_A71C(static_cast<unsigned char*>(object) + 8, destroyMember);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
