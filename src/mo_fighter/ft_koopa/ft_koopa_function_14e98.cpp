#pragma force_active on
struct FtClassInfoX {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_102_data_7798[];
void __ct__11ftClassInfoFb(FtClassInfoX*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(FtClassInfoX*, int, void*);
}

extern "C" FtClassInfoX* fn_102_14E98(FtClassInfoX* self) {
    __ct__11ftClassInfoFb(self, false);
    self->typeInfo = lbl_102_data_7798;
    self->vtable = lbl_102_data_7798 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0x30, self);
    return self;
}
