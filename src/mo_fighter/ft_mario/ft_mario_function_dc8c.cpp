#pragma force_active on
extern "C" void operator delete(void*);
extern "C" void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void* self, int kind, void* info);
extern "C" void* __dt__11ftClassInfoFv(void* self, short flag);
extern char lbl_91_data_76BC[];
extern char g_ftClassInfoNull[];

extern "C" void* fn_91_DC8C(void* self, short deleting) {
    if (self != 0) {
        *(char**)((char*)self + 8) = lbl_91_data_76BC;
        *(char**)self = lbl_91_data_76BC + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(self, 0);
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
