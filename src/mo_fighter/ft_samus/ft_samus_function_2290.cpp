#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_22FC(void*, short);
extern "C" void* fn_94_2158(void*, short);

extern "C" void* fn_94_2290(void* object, short deleting) {
    if (object != 0) {
        short minusOne = -1;
        fn_94_22FC(static_cast<unsigned char*>(object) + 0x50, minusOne);
        fn_94_2158(object, minusOne);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
