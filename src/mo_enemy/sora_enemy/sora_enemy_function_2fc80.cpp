#pragma force_active on
extern "C" void* fn_27_5C674(void*, short);

extern "C" void* fn_41_2FC80(void* p, short p2) {
    if (p != 0) {
        fn_27_5C674(p, -1);
        if (p2 > 0) {
            operator delete(p);
        }
    }
    return p;
}
