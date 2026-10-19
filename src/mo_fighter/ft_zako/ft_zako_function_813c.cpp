#pragma force_active on
extern "C" {
void fn_126_7FA4(void* object, short deleting);
void __dl__FPv(void* p);

void* fn_126_813C(void* object, short deleting) {
    if (object != 0) {
        fn_126_7FA4(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
