#pragma force_active on
void operator delete(void*);
extern "C" void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void* self, int kind, void* info);
extern "C" void* __dt__11ftClassInfoFv(void* self, short flag);
extern char lbl_117_data_83F4[];
extern char g_ftClassInfoNull[];

extern "C" void* fn_117_E0A4(void* self, short deleting) {
    if (self != 0) {
        *(char**)((char*)self + 8) = lbl_117_data_83F4;
        *(char**)self = lbl_117_data_83F4 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0x20, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(self, 0);
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
