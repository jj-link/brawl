#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_4790(void* ptr, short count);
extern "C" void* fn_94_2158(void* object, short shouldDelete);

extern "C" void* fn_94_1536C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_4790(storage + 0x50, -1);
        fn_94_2158(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
