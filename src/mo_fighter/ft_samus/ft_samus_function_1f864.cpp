#pragma force_active on
extern "C" {
void operator delete(void*);
void* fn_94_15494(void* p, short n);
void* fn_94_1F8DC(void* object, short deleting);
void* fn_94_154D4(void* object, short deleting);
}

extern "C" void* fn_94_1F864(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_15494(storage + 0x68, -1);
        fn_94_1F8DC(storage + 0x30, -1);
        fn_94_154D4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
