#pragma force_active on
extern "C" void __ct__11ftClassInfoFb(void* self, bool isNull);
extern "C" void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void* self, int kind, void* info);
extern char lbl_117_data_83F4[];

extern "C" void* fn_117_E04C(void* self) {
    __ct__11ftClassInfoFb(self, false);
    *(char**)((char*)self + 8) = lbl_117_data_83F4;
    *(char**)self = lbl_117_data_83F4 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0x20, self);
    return self;
}
