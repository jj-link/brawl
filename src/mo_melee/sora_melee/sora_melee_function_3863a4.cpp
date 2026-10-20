#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_98F88[];
extern char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void* self, int kind, void* info);
void* __dt__11ftClassInfoFv(void* self, short flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_3863A4(void* self, int flag) {
    if (self) {
        ((void**)self)[2] = (void*)lbl_27_data_98F88;
        ((void**)self)[0] = (void*)(lbl_27_data_98F88 + 8);
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0x1c, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
