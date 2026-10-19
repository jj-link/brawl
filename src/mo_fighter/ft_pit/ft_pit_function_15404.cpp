#pragma force_active on
extern "C" {
void fn_112_5480(void*, short);
void fn_112_15474(void*, short);

void* fn_112_15404(void* object, short deleting) {
    if (object != 0) {
        fn_112_5480(static_cast<char*>(object) + 0xF6C8, static_cast<short>(-1));
        fn_112_15474(static_cast<char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
