#pragma force_active on
typedef unsigned int u32;

enum ftKind { ftKind_Dummy = 0 };

struct Entry {
    u32 m_0;
    u32 m_4[2];
};

extern Entry lbl_27_bss_3210[];

class ftCommonDataAccesser {
public:
    u32 getData(ftKind kind) const;
};

u32 ftCommonDataAccesser::getData(ftKind kind) const {
    return lbl_27_bss_3210[kind].m_0;
}
