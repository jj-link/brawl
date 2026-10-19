#pragma force_active on
extern "C" {
void fn_126_1DC4(void*, short);
void fn_126_1D68(void*, short);
void __dl__FPv(void*);

void* fn_126_30A8(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_126_1DC4(storage + 0x20, 0);
        if (object) fn_126_1D68(storage + 0x8, 0);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
