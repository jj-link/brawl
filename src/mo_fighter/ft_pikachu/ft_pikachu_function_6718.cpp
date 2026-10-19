#pragma force_active on
extern "C" void fn_27_69684(void*, short);

extern "C" void* fn_98_6718(void* member, int deleting) {
    if (member) {
        fn_27_69684(member, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) operator delete(member);
    }
    return member;
}
