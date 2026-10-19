#pragma force_active on
void operator delete(void*);
extern "C" void* fn_95_23BC(void*, short);
extern "C" void* fn_95_22E0(void*, short);

extern "C" void* fn_95_39D0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_23BC(storage + 0x50, -1);
        fn_95_22E0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
