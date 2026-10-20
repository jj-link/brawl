#pragma force_active on
typedef int s32;

struct AIMgrOwner {
    unsigned char pad_0[0x4];
    void* m_4;
};

struct AIMgrInner {
    unsigned char pad_0[0x58];
    s32 m_58;
};

extern "C" {
extern void* g_aiMgr;
s32 fn_27_1F1C1C(void* p, s32 id);

s32 fn_27_124718(AIMgrOwner* self) {
    AIMgrInner* inner = (AIMgrInner*)self->m_4;
    return fn_27_1F1C1C(g_aiMgr, inner->m_58);
}
}
