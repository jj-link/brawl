#include <so/model/so_model_module_impl.h>
#pragma force_active on
extern "C" void fn_8003E6DC(const Matrix*, Vec3f*);
extern "C" void fn_8003E828(Matrix*, const Vec3f*, Matrix*);
extern const float lbl_27_rodata_300;
extern const float lbl_27_rodata_304;
Vec3f soModelModuleImpl::getNodeGlobalPosition(u32 id, const Vec3f* offset, bool flag, bool removeScale) {
    Matrix matrix(true);
    getNodeGlobalMtx(id, &matrix, flag);
    if (removeScale == true) {
        Vec3f scale;
        fn_8003E6DC(&matrix, &scale);
        if (lbl_27_rodata_300 != scale.m_x || lbl_27_rodata_300 != scale.m_y || lbl_27_rodata_300 != scale.m_z) {
            scale.m_x = lbl_27_rodata_300 / scale.m_x;
            scale.m_y = lbl_27_rodata_300 / scale.m_y;
            scale.m_z = lbl_27_rodata_300 / scale.m_z;
            fn_8003E828(&matrix, &scale, &matrix);
        }
    }
    Vec3f result;
    if (lbl_27_rodata_304 != offset->m_x || lbl_27_rodata_304 != offset->m_y || lbl_27_rodata_304 != offset->m_z) {
        matrix.mulPos(offset, &result);
    } else {
        float z = matrix.m[2][3];
        float y = matrix.m[1][3];
        float x = matrix.m[0][3];
        result.m_x = x;
        result.m_y = y;
        result.m_z = z;
    }
    return result;
}