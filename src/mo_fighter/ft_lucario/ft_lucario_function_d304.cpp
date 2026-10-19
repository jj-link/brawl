#pragma force_active on
extern "C" void __ct__11ftClassInfoFb(void* self, bool isNull);
extern "C" void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void* self, int kind, void* info);
extern unsigned char lbl_118_data_6214[];

extern "C" void* fn_118_D304(void* self) {
    __ct__11ftClassInfoFb(self, false);
    unsigned char* table = lbl_118_data_6214;
    *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x8) = table;
    *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x0) = table + 0x8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0x21, self);
    return self;
}
