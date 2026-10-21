#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_100_30AC(void*, short);
void* fn_100_3108(void*, short);
void* fn_27_CBF58(void*, short);
}

extern "C" void* fn_100_3014(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_27_97968(storage + 0x6C, destroy);
        fn_27_1CCCC(storage + 0x5C, destroy);
        fn_100_30AC(storage + 0x50, destroy);
        fn_100_3108(storage + 0x38, destroy);
        if (object != 0) {
            fn_27_CBF58(object, destroy);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
