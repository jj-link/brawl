#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_BED74(void*, short);

extern "C" void* fn_121_644C(void* obj, short flag) {
    if (obj != 0) {
        fn_27_BED74(obj, static_cast<short>(-1));
        if (flag > 0) {
            operator delete(obj);
        }
    }
    return obj;
}
