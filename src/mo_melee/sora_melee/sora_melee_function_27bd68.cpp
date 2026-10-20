#pragma force_active on
typedef unsigned char u8;
typedef float f32;

extern const f32 lbl_27_rodata_4598;

class grTenganEvent {
public:
    u8 pad_00[0x0c];
    f32 m_0c;
    u8 pad_10[0xa4 - 0x10];
    int m_a4;
    void end();
};

void grTenganEvent::end() {
    m_a4 = 0;
    m_0c = lbl_27_rodata_4598;
}
