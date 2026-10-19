#pragma force_active on
extern "C" void* fn_94_15D34(void*, short);
extern "C" void* fn_94_161BC(void*, short);

extern "C" void* fn_94_1614C(void* object, short deleting) {
    if (object != 0) {
        fn_94_15D34(static_cast<unsigned char*>(object) + 0x8330, static_cast<short>(-1));
        fn_94_161BC(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
