#pragma force_active on
extern "C" {
void* fn_107_3400(void* object, short deleting);
void* fn_107_67C0(void* ptr, short size);
void __dl__FPv(void* ptr);

void* fn_107_3390(void* object, short deleting) {
    if (object != 0) {
        fn_107_3400(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_107_67C0(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
