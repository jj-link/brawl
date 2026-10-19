#pragma force_active on
extern "C" {
void fn_27_B21D0(void*, short);
void fn_27_CB4A0(void*, short);
void __dl__FPv(void*);

void* fn_111_4EBC(void* object, short deleting) {
    if (object != 0) {
        short destroy = -1;
        fn_27_B21D0(static_cast<char*>(object) + 0x50, destroy);
        if (object != 0) {
            fn_27_CB4A0(object, destroy);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
