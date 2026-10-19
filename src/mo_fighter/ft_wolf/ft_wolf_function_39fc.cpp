#pragma force_active on
extern "C" void* fn_27_5C674(void*, short);

extern "C" {
void* fn_125_39FC(void* p, short flag);
}

extern "C" void* fn_125_39FC(void* p, short flag) {
    if (p != 0) {
        fn_27_5C674(p, -1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
