#pragma force_active on
typedef int s32;

struct Entry {
    s32* m_0;
    s32 m_4;
    s32 m_8;
};

extern Entry lbl_27_bss_3210[];

extern "C" s32 fn_27_148524(void* self, s32 kind) {
    (void)self;
    switch (kind) {
        case 6: return lbl_27_bss_3210[6].m_0[43];
        case 19: return lbl_27_bss_3210[19].m_0[41];
        case 44: return lbl_27_bss_3210[44].m_0[43];
        default: return 0;
    }
}
