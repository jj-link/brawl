#pragma force_active on
extern "C" void fn_98_3228(void*, short);

extern "C" void* fn_98_31CC(void* member, int deleting) {
    if (member) {
        fn_98_3228(member, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) operator delete(member);
    }
    return member;
}
