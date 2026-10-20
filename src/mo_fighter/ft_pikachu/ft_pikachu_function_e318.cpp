#include <new>
#pragma force_active on

extern "C" {
extern char lbl_98_data_7364[];
extern char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void*, int, void*);
void* __dt__11ftClassInfoFv(void*, short);

void* fn_98_E318(char* self, short deleting) {
    if (self) {
        *reinterpret_cast<char**>(self + 8) = lbl_98_data_7364;
        *reinterpret_cast<char**>(self) = lbl_98_data_7364 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 7, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(self, 0);
        if (deleting > 0) operator delete(self);
    }
    return self;
}
}
