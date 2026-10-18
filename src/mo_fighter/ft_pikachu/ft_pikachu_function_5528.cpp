#pragma force_active on
extern "C" {
void fn_27_327F54(void*, short);
void __dl__FPv(void*);

void* fn_98_5528(void* object, short deleting) {
    if (object) {
        fn_27_327F54(static_cast<char*>(object) + 4, short(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
