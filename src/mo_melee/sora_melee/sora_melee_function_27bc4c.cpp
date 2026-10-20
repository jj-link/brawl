#include <types.h>
#pragma force_active on

extern const f32 lbl_27_rodata_4598;

class grTenganEvent {
public:
    void update(float delta);
    f32 m_pos;       // 0x00
    u8 m_pad04[0x8];
    f32 m_timer;     // 0x0c
    u8 m_pad10[0x94];
    s32 m_state;     // 0xa4
};

void grTenganEvent::update(float delta) {
    if (m_state == 0) {
        return;
    }
    if (m_state == 1) {
        if (m_timer >= lbl_27_rodata_4598) {
            m_timer -= delta;
            if (m_timer < lbl_27_rodata_4598) {
                m_state = 2;
            }
        }
    }
    m_pos += delta;
}
