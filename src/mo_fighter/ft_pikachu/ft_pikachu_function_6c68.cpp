#pragma force_active on
extern "C" void* fn_98_47F8(void*, short);

extern "C" void* fn_98_6C68(void* accesser, int deleting) {
    if (accesser) {
        fn_98_47F8(accesser, static_cast<short>(0));
        if (static_cast<short>(deleting) > 0) operator delete(accesser);
    }
    return accesser;
}
