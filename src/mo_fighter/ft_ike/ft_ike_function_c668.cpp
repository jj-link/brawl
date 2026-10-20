#pragma force_active on
struct ClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_119_data_5C60[];
extern unsigned char g_ftClassInfoNull[];
void __dt__11ftClassInfoFv(ClassInfo*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ClassInfo*, int, void*);
void __dl__FPv(void*);
}

extern "C" ClassInfo* fn_119_C668(ClassInfo* self, short deleting) {
    if (self) {
        self->typeInfo = lbl_119_data_5C60;
        self->vtable = lbl_119_data_5C60 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0x22, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(self, 0);
        if (deleting > 0) __dl__FPv(self);
    }
    return self;
}
