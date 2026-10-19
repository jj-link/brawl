#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_21028(void*, short);

extern "C" void* fn_117_210E8(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_117_21028(static_cast<unsigned char*>(object) + 4, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
