#include <types.h>
#pragma force_active on

enum ftKind { ftKind_Dummy };

extern "C" s32 fn_27_1454C0(const void* self);

struct Entry {
    s32 m_0;
    s32* m_4;
    s32 m_8;
};

extern Entry lbl_27_bss_3210[];

class ftCommonDataAccesser {
public:
    s32 getParam(ftKind kind) const;
};

s32 ftCommonDataAccesser::getParam(ftKind kind) const {
    s32 idx = fn_27_1454C0(this);
    return lbl_27_bss_3210[kind].m_4[idx];
}
