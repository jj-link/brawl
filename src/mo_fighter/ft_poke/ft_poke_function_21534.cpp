#pragma force_active on
struct ftClassInfoLike {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_116_data_B9E4[];
void __ct__11ftClassInfoFb(ftClassInfoLike*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfoLike*, int, ftClassInfoLike*);
}

extern "C" ftClassInfoLike* fn_116_21534(ftClassInfoLike* self) {
    __ct__11ftClassInfoFb(self, false);
    self->typeInfo = lbl_116_data_B9E4;
    self->vtable = lbl_116_data_B9E4 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0x1f, self);
    return self;
}
