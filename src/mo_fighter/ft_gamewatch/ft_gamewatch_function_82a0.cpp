#pragma force_active on
extern "C" void* fn_107_82FC(void* object, short deleting);

extern "C" void* fn_107_82A0(void* p, short del) {
    if (p != 0) {
        fn_107_82FC(p, 0);
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}
