#pragma force_active on

class ftClassInfo {
public:
    void* vtbl;
    void* pad;
    void* data;
};

extern "C" {
extern char lbl_100_data_6184[];
extern char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void*, int, void*);
void __dt__11ftClassInfoFv(void*, short);
void __dl__FPv(void*);

ftClassInfo* fn_100_C758(ftClassInfo* self, short flag) {
    if (self) {
        self->data = lbl_100_data_6184;
        self->vtbl = lbl_100_data_6184 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 9, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
