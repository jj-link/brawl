#pragma force_active on
extern "C" {
extern unsigned char lbl_101_data_8898[];
void __ct__11ftClassInfoFb(void*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void*, int, void*);
}

extern "C" void* fn_101_10D78(void* self) {
    __ct__11ftClassInfoFb(self, false);
    *reinterpret_cast<unsigned char**>(reinterpret_cast<unsigned char*>(self) + 8) = lbl_101_data_8898;
    *reinterpret_cast<unsigned char**>(self) = lbl_101_data_8898 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 10, self);
    return self;
}
