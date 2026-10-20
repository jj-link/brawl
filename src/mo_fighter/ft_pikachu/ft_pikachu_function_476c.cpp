#pragma force_active on
extern "C" void* fn_27_B5324(void*, short);
extern "C" void* fn_98_47F8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_98_476C(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_27_B5324(object + 0x20, memberDeleting);
        char* sub = object + 0x10;
        if (sub) fn_98_47F8(sub, short(0));
        if (object) fn_98_47F8(object, short(0));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
