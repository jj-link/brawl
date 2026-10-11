#include <so/resource/so_resource_id_accesser.h>

// These exports are the concrete resource-accessor implementations, not virtual dispatch.
extern "C" u32 fn_118_13D44(soResourceIdAccesserImpl* object) {
    return object->soResourceIdAccesserImpl::getEtcResId();
}
extern "C" u32 fn_118_13D4C(soResourceIdAccesserImpl* object) {
    return object->soResourceIdAccesserImpl::getBinResId();
}
extern "C" u32 fn_118_13D54(soResourceIdAccesserImpl* object) {
    return object->soResourceIdAccesserImpl::getAnmResId();
}
extern "C" u32 fn_118_13D5C(soResourceIdAccesserImpl* object) {
    return object->soResourceIdAccesserImpl::getMdlResIndex();
}
extern "C" u32 fn_118_13D64(soResourceIdAccesserImpl* object) {
    return object->soResourceIdAccesserImpl::getMdlResId();
}
extern "C" u32 fn_118_13D6C(soResourceIdAccesserImpl* object) {
    return object->soResourceIdAccesserImpl::getTexResIndex();
}
extern "C" u32 fn_118_13D74(soResourceIdAccesserImpl* object) {
    return object->soResourceIdAccesserImpl::getTexResId();
}
extern "C" void fn_118_13D7C(soResourceIdAccesserImpl* object, u16 index) {
    object->soResourceIdAccesserImpl::setTexResIndex(index);
}
extern "C" void fn_118_13D84(soResourceIdAccesserImpl* object, u16 index) {
    object->soResourceIdAccesserImpl::setMdlResIndex(index);
}
extern "C" void fn_118_13D8C(soResourceIdAccesserImpl* object, u32 id) {
    object->soResourceIdAccesserImpl::setTexResId(id);
}
extern "C" void fn_118_13D94(soResourceIdAccesserImpl* object, u32 id) {
    object->soResourceIdAccesserImpl::setMdlResId(id);
}
extern "C" void fn_118_13D9C(soResourceIdAccesserImpl* object, u32 id) {
    object->soResourceIdAccesserImpl::setAnmResId(id);
}
extern "C" void fn_118_13DA4(soResourceIdAccesserImpl* object, u32 id) {
    object->soResourceIdAccesserImpl::setResIdPacked(id);
}
