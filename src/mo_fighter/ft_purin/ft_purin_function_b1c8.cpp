#pragma force_active on
struct PurinClassInfo {
    void* m_vtbl;
    void* m_pad;
    void* m_data;
};

extern "C" {
void* __ct__11ftClassInfoFb(PurinClassInfo* info, bool isNull);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(PurinClassInfo* info, int kind, PurinClassInfo* data);
extern char lbl_124_data_5AB8[];
}

extern "C" PurinClassInfo* fn_124_B1C8(PurinClassInfo* self) {
    __ct__11ftClassInfoFb(self, false);
    self->m_data = lbl_124_data_5AB8;
    self->m_vtbl = lbl_124_data_5AB8 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(self, 0x25, self);
    return self;
}
