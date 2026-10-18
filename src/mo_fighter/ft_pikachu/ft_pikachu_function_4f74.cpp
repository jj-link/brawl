#pragma force_active on
extern "C" {
void* fn_98_4FD4(void*, short);
void __dl__FPv(void*);

void* fn_98_4F74(void* object, short deleting) {
    if (object) {
        fn_98_4FD4(static_cast<char*>(object) + 8, short(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
