#pragma force_active on
extern "C" void fn_27_199B5C(void*, int, int);
extern "C" void fn_27_6A244(void*, void*, void*);

extern "C" void* fn_100_7874(void* object, void* articleAccesser) {
    fn_27_199B5C(object, 0xC, 0);
    fn_27_6A244(static_cast<char*>(object) + 0x27C, articleAccesser, object);
    return object;
}
