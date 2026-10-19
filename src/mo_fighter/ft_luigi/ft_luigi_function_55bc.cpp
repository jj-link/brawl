#pragma force_active on
extern "C" void fn_27_4B53C(void*, short);
extern "C" void fn_27_19C45C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_99_55BC(void* object, short deleting) {
    if (object) {
        short destroyMember = -1;
        fn_27_4B53C(static_cast<unsigned char*>(object) + 0x17C, destroyMember);
        fn_27_19C45C(object, destroyMember);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
