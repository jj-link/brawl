#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_1536C(void*, short);
extern "C" void* fn_94_1C3DC(void*, short);
extern "C" void* fn_94_1C468(void*, short);
extern "C" void* fn_94_1C4F4(void*, short);
extern "C" void* fn_94_1C580(void*, short);

extern "C" void* fn_94_1C34C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_1536C(storage + 0x2D0, -1);
        fn_94_1C3DC(storage + 0x21C, -1);
        fn_94_1C468(storage + 0x168, -1);
        fn_94_1C4F4(storage + 0xB4, -1);
        fn_94_1C580(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
