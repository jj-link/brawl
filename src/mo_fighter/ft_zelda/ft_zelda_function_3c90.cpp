#pragma force_active on
extern "C" void* fn_104_3C90(void* p, short flag) {
    if (p != 0 && flag > 0) {
        ::operator delete(p);
    }
    return p;
}
