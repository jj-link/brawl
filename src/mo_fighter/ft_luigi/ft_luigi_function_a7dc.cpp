#pragma force_active on
extern "C" {
void* fn_99_A77C(void* object, short deleting);
void fn_99_A648(void* object, short deleting);
}

extern "C" void* fn_99_A7DC(void* object, short deleting) {
    if (object) {
        fn_99_A77C(static_cast<unsigned char*>(object) + 0x1C8, -1);
        if (object) {
            fn_99_A648(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
