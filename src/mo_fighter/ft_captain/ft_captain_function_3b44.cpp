#pragma force_active on
extern "C" {
void* fn_27_1A241C(void*, short);
void* fn_100_3BE0(void*, short);
void fn_100_1F14(void*, short);
void* fn_100_3C20(void*, short);
}

extern "C" void* fn_100_3B44(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        if (static_cast<void*>(storage + 0x30) != 0) {
            fn_27_1A241C(storage + 0x40, -1);
            fn_100_3BE0(storage + 0x30, 0);
        }
        if (object != 0) {
            fn_100_1F14(storage + 0x20, 0);
            fn_100_3C20(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
