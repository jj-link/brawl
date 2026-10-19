#pragma force_active on
extern "C" void fn_41_55754(void*, short);

extern "C" void* fn_41_55820(void* p, short flag) {
    if (p != 0) {
        if (p != 0) {
            fn_41_55754(static_cast<char*>(p) + 4, -1);
        }
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
