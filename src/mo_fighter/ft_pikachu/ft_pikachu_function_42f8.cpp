#pragma force_active on
extern "C" {
void* fn_98_4358(void*, short);
void __dl__FPv(void*);

void* fn_98_42F8(void* object, short deleting) {
    if (object) {
        fn_98_4358(static_cast<char*>(object) + 0x0C, short(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
