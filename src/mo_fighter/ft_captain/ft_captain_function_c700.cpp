#pragma force_active on
class ftClassInfo {
public:
    void* vtbl;
    void* pad;
    void* data;
};

extern "C" {
void* __ct__11ftClassInfoFb(ftClassInfo*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfo*, int, ftClassInfo*);
extern char lbl_100_data_6184[];

ftClassInfo* fn_100_C700(ftClassInfo* self) {
    __ct__11ftClassInfoFb(self, false);
    self->data = lbl_100_data_6184;
    self->vtbl = lbl_100_data_6184 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 9, self);
    return self;
}
}
