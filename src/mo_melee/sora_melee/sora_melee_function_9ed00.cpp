#pragma force_active on
struct ftClassInfo {
    int vtable;
    int unk4;
    int unk8;
    int m_isNull;
};

extern "C" int fn_27_9ED00(const ftClassInfo *self) {
    return self->m_isNull < 0;
}
