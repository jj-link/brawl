#pragma force_active on
extern "C" {
void* fn_98_1AB0(void*, short);
}

extern "C" void* fn_98_1BCC(void* member, int deleting) {
    if (member) {
        fn_98_1AB0(member, static_cast<short>(0));
        if (static_cast<short>(deleting) > 0) operator delete(member);
    }
    return member;
}
