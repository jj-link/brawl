#pragma force_active on
extern "C" void fn_27_22A38(void*, short);
extern "C" void fn_27_1A2910(void*, short);

extern "C" void* fn_99_5AA4(void* object, short deleting) {
    if (object) {
        short destroyMember = -1;
        fn_27_22A38(static_cast<unsigned char*>(object) + 0x34, destroyMember);
        fn_27_1A2910(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
