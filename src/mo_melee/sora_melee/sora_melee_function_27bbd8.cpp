#pragma force_active on
typedef float f32;
typedef int s32;

extern const f32 lbl_27_rodata_4598;

class grTenganEvent {
public:
    grTenganEvent();
    f32 m_00;
    unsigned char m_04[0x0c - 0x04];
    f32 m_0c;
    unsigned char m_10[0xa4 - 0x10];
    s32 m_a4;
    s32 m_a8;
};

grTenganEvent::grTenganEvent() {
    m_a8 = 0;
    m_00 = lbl_27_rodata_4598;
    m_a4 = 0;
    m_0c = lbl_27_rodata_4598;
}
