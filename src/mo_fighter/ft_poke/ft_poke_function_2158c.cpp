#pragma force_active on
struct ftClassInfoLike {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_116_data_B9E4[];
extern unsigned char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfoLike*, int, void*);
void __dt__11ftClassInfoFv(ftClassInfoLike*, short);
void __dl__FPv(void*);
}

extern "C" ftClassInfoLike* fn_116_2158C(ftClassInfoLike* self, short deleting) {
    if (self) {
        self->typeInfo = lbl_116_data_B9E4;
        self->vtable = lbl_116_data_B9E4 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0x1f, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(self, 0);
        if (deleting > 0) operator delete(self);
    }
    return self;
}
