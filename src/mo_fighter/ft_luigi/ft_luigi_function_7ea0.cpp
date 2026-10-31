#pragma force_active on
extern "C" void* fn_99_7DB4(void*, int);

extern "C" void* fn_99_7EA0(void* object, int mode) {
    switch (mode) {
    case 0:
        return object;
    case 1:
        return (unsigned char*)object + 0x480;
    case 2:
        return fn_99_7DB4(object, mode);
    default:
        return fn_99_7DB4(object, mode);
    }
}
