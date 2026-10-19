#pragma force_active on
extern "C" {
extern char lbl_98_data_7364[];
void __ct__11ftClassInfoFb(void*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void*, int, void*);

void* fn_98_E2C0(void* self) {
    __ct__11ftClassInfoFb(self, false);
    *reinterpret_cast<char**>(static_cast<char*>(self) + 8) = lbl_98_data_7364;
    *reinterpret_cast<char**>(self) = lbl_98_data_7364 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 7, self);
    return self;
}
}
