#include <types.h>
#pragma force_active on

class ftClassInfo {
public:
    void* vtbl;
    void* pad;
    void* data;
};

extern "C" {
extern char lbl_114_data_808C[];
extern char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void*, int, void*);
void __dt__11ftClassInfoFv(void*, short);
void __dl__FPv(void*);

ftClassInfo* fn_114_10630(ftClassInfo* self, short flag) {
    if (self) {
        self->data = lbl_114_data_808C;
        self->vtbl = lbl_114_data_808C + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0x1a, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
