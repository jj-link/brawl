#pragma force_active on
struct ftClassInfoStub {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern unsigned char lbl_92_data_6304[];
extern unsigned char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfoStub*, int, void*);
void __dt__11ftClassInfoFv(ftClassInfoStub*, short);
void __dl__FPv(void*);
}

extern "C" ftClassInfoStub* fn_92_C980(ftClassInfoStub* self, short deleting) {
    if (self) {
        self->typeInfo = lbl_92_data_6304;
        self->vtable = lbl_92_data_6304 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 1, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(self, 0);
        if (deleting > 0) operator delete(self);
    }
    return self;
}
