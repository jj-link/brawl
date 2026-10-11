#include <so/resource/so_resource_id_accesser.h>

// All archive categories defer to the object's virtual archive-ID accessor.
extern "C" u32 fn_118_13CEC(soResourceIdAccesser* object) {
    return object->getArchiveId();
}
extern "C" u32 fn_118_13CFC(soResourceIdAccesser*) {
    return 0xFFFFFFFF;
}
extern "C" u32 fn_118_13D04(soResourceIdAccesser* object) {
    return object->getArchiveId();
}
extern "C" u32 fn_118_13D14(soResourceIdAccesser* object) {
    return object->getArchiveId();
}
extern "C" u32 fn_118_13D24(soResourceIdAccesser* object) {
    return object->getArchiveId();
}
extern "C" u32 fn_118_13D34(soResourceIdAccesser* object) {
    return object->getArchiveId();
}
