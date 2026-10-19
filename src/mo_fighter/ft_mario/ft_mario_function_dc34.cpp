#pragma force_active on
extern "C" {
extern unsigned char lbl_91_data_76BC[];
void __ct__11ftClassInfoFb(void*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void*, int, void*);

struct MarioClassInfoLayout {
    void* vtable;
    void* pad;
    void* data;
};

void* fn_91_DC34(void* self) {
    MarioClassInfoLayout* info = static_cast<MarioClassInfoLayout*>(self);
    __ct__11ftClassInfoFb(self, false);
    info->data = lbl_91_data_76BC;
    info->vtable = lbl_91_data_76BC + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0, self);
    return self;
}
}
