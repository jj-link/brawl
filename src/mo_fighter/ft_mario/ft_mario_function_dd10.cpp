#pragma force_active on
extern "C" {
extern unsigned char lbl_91_data_7664[];
void __ct__11ftClassInfoFb(void*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void*, int, void*);

void* fn_91_DD10(void* self) {
    __ct__11ftClassInfoFb(self, false);
    *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x8) = lbl_91_data_7664;
    *reinterpret_cast<unsigned char**>(self) = lbl_91_data_7664 + 0x8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0x36, self);
    return self;
}
}
