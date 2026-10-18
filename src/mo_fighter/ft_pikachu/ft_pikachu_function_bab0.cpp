#pragma force_active on
extern "C" {
void* fn_98_BA50(void*, short);
void operator delete(void*);

void* fn_98_BAB0(void* object, short deleting) {
    if (object) {
        fn_98_BA50(static_cast<char*>(object) + 4, short(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
