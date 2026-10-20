#pragma force_active on
extern "C" void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void* self, int kind, void* info);
extern "C" void __dt__11ftClassInfoFv(void* self, short flag);
extern "C" void __dl__FPv(void*);
extern char lbl_118_data_6214[];
extern char g_ftClassInfoNull[];

extern "C" void* fn_118_D35C(void* self, short deleting) {
    if (self != 0) {
        *(char**)((char*)self + 8) = lbl_118_data_6214;
        *(char**)self = lbl_118_data_6214 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0x21, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(self, 0);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
