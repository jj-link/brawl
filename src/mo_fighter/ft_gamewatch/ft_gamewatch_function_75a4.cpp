#pragma force_active on
void operator delete(void*);
extern "C" void* fn_107_7610(void*, short);
extern "C" void* fn_107_4198(void*, short);

extern "C" void* fn_107_75A4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_107_7610(storage + 0x24, -1);
        fn_107_4198(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
