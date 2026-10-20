#pragma force_active on
// fn_93_4B20 destroys the link embedded member whose storage begins at +0xB4
// of the passed object and then applies the outer object's own cleanup chain,
// mirroring the published reverse-construction destructor pattern.
extern "C" {
void* fn_27_D2904(void* member, short deleteFlag);
void* fn_93_4AA8(void* object, short deleting);
void __dl__FPv(void*);
}

extern "C" void* fn_93_4B20(void* object, short deleteFlag) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0xB4, -1);
        if (object != 0) {
            fn_93_4AA8(object, 0);
        }
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
