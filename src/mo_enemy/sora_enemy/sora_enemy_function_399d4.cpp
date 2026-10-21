#pragma force_active on
extern "C" {
void* fn_27_CB4A0(void*, short);
void* fn_41_2A480(void*, short);
void* __dt__18emTargetSearchUnitFv(void*, short);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void* fn_27_CB048(void*, short);
void* fn_27_D02C8(void*, short);
void* fn_41_2CBC(void*, short);
void __dl__FPv(void*);

void* fn_41_399D4(void* object, short deleting) {
    if (object) {
        char* members = static_cast<char*>(object);
        short destroy = -1;
        fn_27_CB4A0(members + 0x5d2c, destroy);
        __destroy_arr(members + 0x5cac, reinterpret_cast<void (*)(void*, int)>(fn_41_2A480), 8, 0x10);
        __destroy_arr(members + 0x5c7c, reinterpret_cast<void (*)(void*, int)>(__dt__18emTargetSearchUnitFv), 0x18, 2);
        fn_27_CB048(members + 0x5a0c, destroy);
        fn_27_D02C8(members + 0x5310, destroy);
        fn_41_2CBC(object, 0);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
}
