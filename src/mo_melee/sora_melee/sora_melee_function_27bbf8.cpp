#pragma force_active on
typedef float f32;
typedef int s32;
typedef unsigned char u8;

extern const f32 lbl_27_rodata_4598;

class grTenganEvent {
public:
    virtual void dummy();
    virtual ~grTenganEvent();
    u8 _00[0xC - 4];
    f32 m_c;
    u8 _10[0xA4 - 0x10];
    s32 m_a4;
};

grTenganEvent::~grTenganEvent() {
    m_a4 = 0;
    m_c = lbl_27_rodata_4598;
}
