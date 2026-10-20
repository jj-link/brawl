#pragma force_active on
extern char lbl_27_data_7A610[0x24];

struct soWorkRef {
    char* m_cur;
    unsigned char m_flag;
    char* m_base;
};

extern "C" {
void fn_27_2C0904(soWorkRef* self) {
    self->m_flag = 0;
    self->m_base = lbl_27_data_7A610;
    self->m_cur = lbl_27_data_7A610 + 8;
}
}
