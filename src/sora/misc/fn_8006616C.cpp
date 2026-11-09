#include <types.h>
#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>

#pragma force_active on

extern "C" {
void fn_800613B8(Matrix*, void*, u16, const Vec3f*, const Vec3f*, const Vec3f*);
void fn_801ECD70(void*, void*, void*);
void fn_8003ECA0(Matrix*, float, float, float);
extern float lbl_805A1990;
extern float lbl_805A1994;
}

extern "C" void update_odd__7ecTraceFf(void* self, float p1) {
    u8* s = (u8*)self;
    Matrix mtx2(true), mtx(true);
    Vec3f rot, position, rotation, scale;

    if (!(*(u8*)(s + 0x0E) & 0x10)) {
        s32 arr1 = *(s32*)(s + 0x00);
        if (arr1 != 0) {
            Vec3f* entry;
            s32 arr2;
            s32 idx = *(u16*)(s + 0x0C) + 1;
            if (idx >= (s32)*(u16*)(s + 0x08))
                idx = 0;
            entry = (Vec3f*)(arr1 + idx * 0x18);

            scale.m_x = lbl_805A1994;
            scale.m_y = lbl_805A1994;
            scale.m_z = lbl_805A1994;
            rotation.m_x = lbl_805A1990;
            rotation.m_y = lbl_805A1990;
            rotation.m_z = lbl_805A1990;
            position.m_x = lbl_805A1990;
            position.m_y = lbl_805A1990;
            position.m_z = lbl_805A1990;

            fn_800613B8(&mtx, *(void**)(s + 0x44), *(u16*)(s + 0x48),
                        &scale, &rotation, &position);
            fn_801ECD70(&mtx, s + 0x4C, entry);

            arr2 = *(s32*)(s + 0x04);
            if (arr2 != 0) {
                mtx.getRotate(&rot);
                fn_8003ECA0(&mtx2, rot.m_x, rot.m_y, rot.m_z);
                mtx2.mulPos((Vec3f*)(s + 0x64), (Vec3f*)(arr2 + idx * 0x0C));
            }

            fn_800613B8(&mtx, *(void**)(s + 0x44), *(u16*)(s + 0x4A),
                        &scale, &rotation, &position);
            fn_801ECD70(&mtx, s + 0x58, (Vec3f*)((u8*)entry + 0x0C));
        }
        *(u8*)(s + 0x0E) |= 4;
        *(f32*)(s + 0x18) += p1;
    }
}
