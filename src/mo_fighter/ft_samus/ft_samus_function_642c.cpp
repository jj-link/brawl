#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_94_64A4(void*, short);
void* fn_94_6504(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_94_642C(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_27_B5324(storage + 0x30, destroy);
        fn_94_64A4(storage + 0x18, destroy);
        fn_94_6504(storage + 0x04, destroy);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
