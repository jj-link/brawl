#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_126_47CC(void*, short);
void* fn_126_4828(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_126_4754(void* object, short deleting) {
    if (object) {
        unsigned char* storage = (unsigned char*)object;
        int destroy = -1;
        fn_27_B5324(storage + 0x30, destroy);
        fn_126_47CC(storage + 0x18, destroy);
        fn_126_4828(storage + 4, destroy);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
