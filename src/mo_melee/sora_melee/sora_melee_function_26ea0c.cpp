#include <gr/gr_gimmick.h>
#include <mt/mt_matrix.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_43C0;
extern "C" void fn_8003E6DC(const Matrix*, Vec3f*);

extern "C" void fn_27_26EA0C(grGimmick* self) {
    Matrix matrix(true);
    Vec3f position, rotation, scale;
    nw4r::g3d::ScnMdlSimple* model = (*(nw4r::g3d::ScnMdlSimple***)((char*)self + 0x44))[*(int*)((char*)self + 0x178)];
    if (model && model->GetScnMtxPos(&matrix, nw4r::g3d::ScnObj::MTX_WORLD, *(unsigned long*)((char*)self + 0x17c))) {
        float z = matrix.m[2][3];
        float y = matrix.m[1][3];
        float x = matrix.m[0][3];
        position.m_y = y;
        position.m_x = x;
        position.m_z = z;
        matrix.getRotate(&rotation);
        fn_8003E6DC(&matrix, &scale);
        float factor = lbl_27_rodata_43C0;
        float xrot = rotation.m_x;
        float yrot = rotation.m_y;
        float zrot = rotation.m_z;
        float rx = factor * xrot;
        float ry = factor * yrot;
        float rz = factor * zrot;
        rotation.m_x = rx;
        rotation.m_y = ry;
        rotation.m_z = rz;
        self->setPos(&position);
        self->setRot(&rotation);
        self->setScale(&scale);
    }
}