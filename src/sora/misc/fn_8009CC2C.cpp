#include <types.h>
#include <gf/gf_camera.h>
#pragma force_active on

extern "C" double fn_80400AB8(double);
extern "C" int fn_80041D64(void*, void*);
extern f32 lbl_805A1DBC;
extern f32 lbl_805A1DC0;

extern "C" s32 fn_8009CC2C(void* self, void* arg) {
    s32 result = 0;
    char* mgr = (char*)gfCameraManager::getManager();
    if (mgr != 0) {
        f32 pz;
        f32 py;
        f32 px;
        f32 angle;
        px = *(f32*)(mgr + 0x60);
        py = *(f32*)(mgr + 0x64);
        pz = *(f32*)(mgr + 0x68);
        angle = *(f32*)(mgr + 0xd0);
        Vec3f pos;
        pos.m_x = px;
        pos.m_y = py;
        pos.m_z = pz;
        f32 depth = *(f32*)(mgr + 0xcc);
        f32 fov = (f32)fn_80400AB8(angle);
        Vec2f size;
        f32 scaled = depth * fov;
        f32 aspect = *(f32*)(mgr + 0xe4);
        size.m_x = lbl_805A1DBC * scaled;
        size.m_y = size.m_x / aspect;
        Vec2f lo;
        Vec2f hi;
        lo.m_x = pos.m_x - size.m_x * lbl_805A1DC0;
        lo.m_y = pos.m_y - size.m_y * lbl_805A1DC0;
        hi.m_x = pos.m_x + size.m_x * lbl_805A1DC0;
        hi.m_y = pos.m_y + size.m_y * lbl_805A1DC0;
        f32 rect[4];
        register f32 dy2, dx2, dy1, y2, y, dx1, x2, x;
        x2 = hi.m_x;
        x = lo.m_x;
        y2 = hi.m_y;
        y = lo.m_y;
        asm { ps_sub dx1, x, x2 }
        asm { ps_sub dx2, x, x2 }
        asm { ps_sub dy1, y, y2 }
        asm { ps_sub dy2, y, y2 }
        asm { ps_sel dx1, dx1, x2, x }
        asm { ps_sel dy1, dy1, y2, y }
        asm { ps_sel dx2, dx2, x, x2 }
        asm { ps_sel dy2, dy2, y, y2 }
        rect[0] = dx1;
        rect[1] = dy1;
        rect[2] = dx2;
        rect[3] = dy2;
        result = fn_80041D64(rect, arg);
    }
    return result;
}