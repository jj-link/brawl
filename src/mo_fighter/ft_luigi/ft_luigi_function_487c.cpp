#pragma force_active on
extern "C" {
void* fn_27_D2904(void*, short);
void* fn_99_48F4(void*, short);
}

// Destroy the member at 0x318 before the embedded base; only positive flags delete.
extern "C" void* fn_99_487C(void* object, short deleting) {
    if (object) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0x318, -1);
        if (object) {
            fn_99_48F4(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
