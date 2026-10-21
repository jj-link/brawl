#pragma force_active on
typedef unsigned char u8;

typedef struct {
    u8 pad[0x2C];
    u8 m_2c;
} lbl_805A0F88_type;

extern lbl_805A0F88_type *lbl_805A0F88;

u8 fn_8033A77C(void) {
    if (lbl_805A0F88 != 0) {
        return lbl_805A0F88->m_2c;
    }
    return 0;
}
