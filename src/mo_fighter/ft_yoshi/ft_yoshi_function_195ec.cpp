#pragma force_active on
extern "C" {

void* fn_27_BED74(void*, short);
void __dl__FPv(void*);

void* fn_95_195EC(void* obj, short dtor) {
    if (obj != 0) {
        fn_27_BED74(obj, static_cast<short>(-1));
        if ((int)dtor > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}

}
