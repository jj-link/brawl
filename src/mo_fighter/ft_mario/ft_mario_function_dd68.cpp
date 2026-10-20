#pragma force_active on
extern "C" {
extern unsigned char lbl_91_data_7664[];
extern char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void*, int, void*);
void* __dt__11ftClassInfoFv(void*, short);
void* __dl__FPv(void*);

void* fn_91_DD68(void* self, short deleting) {
    if (self != 0) {
        *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x8) = lbl_91_data_7664;
        *reinterpret_cast<unsigned char**>(self) = lbl_91_data_7664 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0x36, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(self, 0);
        if (deleting > 0) operator delete(self);
    }
    return self;
}
}
