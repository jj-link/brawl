#pragma force_active on
extern "C" {
void* fn_98_BBE8(void*, short);
}

extern "C" void* fn_98_BD80(void* p, int deleting) {
    if (p) {
        fn_98_BBE8(p, static_cast<short>(0));
        if (static_cast<short>(deleting) > 0) operator delete(p);
    }
    return p;
}
