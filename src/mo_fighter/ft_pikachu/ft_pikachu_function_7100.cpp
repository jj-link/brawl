#pragma force_active on
extern "C" void* fn_27_CC7EC(void*, short);

extern "C" void* fn_98_7100(void* member, int deleting) {
    if (member) {
        fn_27_CC7EC(member, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) operator delete(member);
    }
    return member;
}
