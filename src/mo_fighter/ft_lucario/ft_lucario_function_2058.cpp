#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_2130(void*, short);
extern "C" void* fn_118_22F4(void*, short);
extern "C" void* fn_118_23BC(void*, short);
extern "C" void* fn_118_2448(void*, short);
extern "C" void* fn_118_24D4(void*, short);
extern "C" void* fn_118_2560(void*, short);
extern "C" void* fn_118_25EC(void*, short);
extern "C" void* fn_118_2678(void*, short);
extern "C" void* fn_118_2704(void*, short);
extern "C" void* fn_118_2790(void*, short);
extern "C" void* fn_118_281C(void*, short);

extern "C" void* fn_118_2058(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_2130(storage + 0x14E0, -1);
        fn_118_22F4(storage + 0x13BC, -1);
        fn_118_23BC(storage + 0x1290, -1);
        fn_118_2448(storage + 0x1164, -1);
        fn_118_24D4(storage + 0x1038, -1);
        fn_118_2560(storage + 0xF0C, -1);
        fn_118_25EC(storage + 0xDE0, -1);
        fn_118_2678(storage + 0xCB4, -1);
        fn_118_2704(storage + 0xB88, -1);
        fn_118_2790(storage + 0xA5C, -1);
        fn_118_281C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}