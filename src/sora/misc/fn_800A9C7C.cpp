#include <types.h>
#include <gf/gf_pad_status.h>
#pragma force_active on

extern const f32 lbl_805A20FC;
extern const f32 lbl_805A2130;
extern const f32 lbl_805A2134;
extern const f32 lbl_805A2138;

struct StickResult {
    f32 x;
    f32 y;
};

extern "C" StickResult fn_800A9C7C(int, const gfPadStatus*);

extern "C" StickResult fn_800A9C7C(int, const gfPadStatus* p)
{
    StickResult out;

    if (p->m_controllerType == gfPadType::WIIMOTE) {
        u32 buttons = p->m_buttonsCurrentFrame2.bits;
        out.y = lbl_805A20FC;
        out.x = lbl_805A20FC;

        if (buttons & 2)
            out.x = lbl_805A2130;
        if (buttons & 1)
            out.x = lbl_805A2134;
        if (buttons & 8)
            out.y = lbl_805A2130;
        if (buttons & 4)
            out.y = lbl_805A2134;
    } else {
        u8 sx = p->m_stickX;
        s8 ax = (s8)sx < 0 ? -(s8)sx : (s8)sx;

        if (ax <= 30) {
            out.x = lbl_805A20FC;
        } else {
            out.x = (f32)(ax - 30) / lbl_805A2138;
            if ((s8)sx < 0)
                out.x = -out.x;
        }

        u8 sy = p->m_stickY;
        s8 ay = (s8)sy < 0 ? -(s8)sy : (s8)sy;

        if (ay <= 30) {
            out.y = lbl_805A20FC;
        } else {
            out.y = (f32)(ay - 30) / lbl_805A2138;
            if ((s8)sy < 0)
                out.y = -out.y;
        }
    }

    return out;
}
