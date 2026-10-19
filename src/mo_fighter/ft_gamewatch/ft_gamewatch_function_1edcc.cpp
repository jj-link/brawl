#pragma force_active on
extern "C" {
void* fn_27_5CC1C(void*, short);
void* fn_27_D3080(void*, short);

void* fn_107_1EDCC(void* object, short deleting) {
    if (object != 0) {
        fn_27_5CC1C(static_cast<unsigned char*>(object) + 0xAC, -1);
        if (object != 0) {
            fn_27_D3080(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}
