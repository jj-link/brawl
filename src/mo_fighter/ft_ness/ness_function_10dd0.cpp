#pragma force_active on
void operator delete(void*);
extern "C" {
extern unsigned char lbl_101_data_8898[];
extern char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void*, int, void*);
void __dt__11ftClassInfoFv(void*, short);
}

extern "C" void* fn_101_10DD0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        *reinterpret_cast<unsigned char**>(members + 8) = lbl_101_data_8898;
        *reinterpret_cast<unsigned char**>(members) = lbl_101_data_8898 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(object, 0xA, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
