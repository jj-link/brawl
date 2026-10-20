#include <cstring>
#pragma force_active on

struct ValueAccesserBase {
    int m_kind;
    const void* m_table;
};

extern char lbl_27_data_139E8[];
extern unsigned char lbl_27_bss_1B14;
extern ValueAccesserBase* lbl_27_bss_1B00[5];

extern "C" {
ValueAccesserBase* fn_27_8B574(ValueAccesserBase* self, int kind) {
    self->m_table = lbl_27_data_139E8;
    if (!lbl_27_bss_1B14) {
        std::memset(lbl_27_bss_1B00, 0, 0x14);
        lbl_27_bss_1B14 = 1;
    }
    lbl_27_bss_1B00[kind] = self;
    self->m_kind = kind;
    return self;
}
}
