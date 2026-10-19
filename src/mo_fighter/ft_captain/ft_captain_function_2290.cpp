#pragma force_active on
extern "C" {
void* fn_100_22FC(void*, short);
void* fn_100_2158(void*, short);
}

extern "C" void* fn_100_2290(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_100_22FC(storage + 0x50, destroy);
        fn_100_2158(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
