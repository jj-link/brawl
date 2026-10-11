#include <so/stageobject.h>

struct MarioArticleVector2 { float x; float y; };
extern "C" {
int fn_27_1DAF80(void*, unsigned int);
Vec3f* fn_91_169EC(Vec3f*, const Vec3f&);
MarioArticleVector2* fn_91_16908(MarioArticleVector2* object, float x, float y) {
    object->x = x;
    object->y = y;
    return object;
}
void fn_91_16914(StageObject* object) {
    Vec3f scale;
    Vec3f rotation;
    Vec3f position;
    scale.m_x = scale.m_y = scale.m_z = object->m_moduleAccesser->m_enumerationStart->m_postureModule->getScale();
    Vec3f sourcePosition = object->m_moduleAccesser->getPostureModule().getPos();
    fn_91_169EC(&position, sourcePosition);
    Vec3f sourceRotation = object->m_moduleAccesser->getPostureModule().getRot(0);
    fn_91_169EC(&rotation, sourceRotation);
    object->m_moduleAccesser->m_enumerationStart->m_modelModule->setNodeSRT(0, &scale, &rotation, &position);
}
#pragma dont_inline on
Vec3f* fn_91_169EC(Vec3f* object, const Vec3f& source) {
    object->m_x = source.m_x;
    object->m_y = source.m_y;
    object->m_z = source.m_z;
    return object;
}
#pragma dont_inline reset
int fn_91_16A08(void* object, unsigned int flags) {
    int result;
    if (flags & 6) {
        result = 0;
    } else {
        result = fn_27_1DAF80(object, flags);
    }
    return result;
}
}
