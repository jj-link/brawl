#pragma force_active on
struct ftClassInfoStub {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern unsigned char lbl_92_data_6304[];
void __ct__11ftClassInfoFb(ftClassInfoStub*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfoStub*, int, void*);
}

extern "C" ftClassInfoStub* fn_92_C928(ftClassInfoStub* self) {
    __ct__11ftClassInfoFb(self, false);
    self->typeInfo = lbl_92_data_6304;
    self->vtable = lbl_92_data_6304 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 1, self);
    return self;
}
