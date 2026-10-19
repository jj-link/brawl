#pragma force_active on
extern "C" void* fn_27_5C674(void*, short);
void operator delete(void*);

extern "C" void* fn_95_3B24(void* p, short flag) {
    if (p != 0) {
        fn_27_5C674(p, -1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
