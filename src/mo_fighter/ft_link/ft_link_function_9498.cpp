#pragma force_active on
extern "C" void* fn_27_C74E8(void* object, short deleting);
extern "C" void* fn_93_93F8(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" {
void* fn_93_9498(void* object, short deleting) {
    if (object != 0) {
        fn_27_C74E8(static_cast<char*>(object) + 0x1A350, -1);
        fn_93_93F8(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
