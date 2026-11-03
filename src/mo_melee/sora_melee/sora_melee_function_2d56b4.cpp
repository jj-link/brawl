#pragma force_active on
#include <mt/mt_matrix.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>

extern char lbl_27_data_7B3F0[];
extern const float lbl_27_rodata_61C8;
extern const float lbl_27_rodata_61E8;
extern "C" void fn_800613B8(Matrix*, nw4r::g3d::ScnMdlSimple*, unsigned short, const Vec3f*, const Vec3f*, const Vec3f*);
extern "C" void fn_801AAF04(void*, int, Matrix*);

extern "C" void fn_27_2D56B4(nw4r::g3d::ScnMdlSimple* self, void* arg1) {
    Matrix matrix(true);
    Vec3f scale;
    Vec3f rotation;
    Vec3f position;
    unsigned short index = 0;
    nw4r::g3d::ResMdl model = self->m_resMdl;
    nw4r::g3d::ResNode node = model.GetResNode(lbl_27_data_7B3F0);
    if (node.IsValid()) {
        unsigned int value;
        if (node.IsValid()) value = node.ptr()->m_nodeIndex;
        else value = 0;
        index = (unsigned short)value;
    }
    position.m_x = lbl_27_rodata_61E8;
    position.m_y = lbl_27_rodata_61E8;
    position.m_z = lbl_27_rodata_61E8;
    rotation.m_x = lbl_27_rodata_61E8;
    rotation.m_y = lbl_27_rodata_61E8;
    rotation.m_z = lbl_27_rodata_61E8;
    scale.m_x = lbl_27_rodata_61C8;
    scale.m_y = lbl_27_rodata_61C8;
    scale.m_z = lbl_27_rodata_61C8;
    fn_800613B8(&matrix, self, index, &scale, &rotation, &position);
    fn_801AAF04(arg1, 0, &matrix);
}
