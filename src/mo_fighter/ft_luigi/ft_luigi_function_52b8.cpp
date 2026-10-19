#pragma force_active on
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_99_5324(void*, short);

extern "C" void* fn_99_52B8(void* object, short deleting) {
    if (object) {
        short destroyMember = -1;
        fn_27_565F0(static_cast<unsigned char*>(object) + 0x14, destroyMember);
        fn_99_5324(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
