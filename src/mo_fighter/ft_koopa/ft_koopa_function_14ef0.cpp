#include <stddef.h>
#pragma force_active on

struct KoopaClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_102_data_7798[];
extern unsigned char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(KoopaClassInfo*, int, void*);
void __dt__11ftClassInfoFv(KoopaClassInfo*, short);
}

extern "C" KoopaClassInfo* fn_102_14EF0(KoopaClassInfo* self, short deleting) {
    if (self) {
        self->typeInfo = lbl_102_data_7798;
        self->vtable = lbl_102_data_7798 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0x30, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(self, 0);
        if (deleting > 0) operator delete(self);
    }
    return self;
}
