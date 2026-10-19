#pragma force_active on
extern "C" {
void* fn_91_BF2C(void*, short);

void* fn_91_BFEC(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) fn_91_BF2C(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
