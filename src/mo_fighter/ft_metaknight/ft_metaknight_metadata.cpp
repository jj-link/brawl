#include <ft/ft_class_info.h>
#include <ft/ft_extend_param_accesser.h>

extern "C" void* __ct__21ftExtendParamAccesserF6ftKind(ftExtendParamAccesser*, ftKind);
extern "C" void* __ct__11ftClassInfoFb(ftClassInfo*, bool);
extern "C" void* __dt__11ftClassInfoFv(ftClassInfo*, s16);
extern "C" const u8 lbl_111_data_28[];
extern "C" const u8 lbl_111_data_5CD4[];

struct MetaKnightMetadataPrefix {
    const u8* primaryMethods;
    u32 baseState;
    const u8* nullableMethods;
};

extern "C" void* fn_111_C41C(ftExtendParamAccesser* object) {
    __ct__21ftExtendParamAccesserF6ftKind(object, Fighter_MetaKnight);
    MetaKnightMetadataPrefix* prefix = reinterpret_cast<MetaKnightMetadataPrefix*>(object);
    prefix->nullableMethods = lbl_111_data_28;
    prefix->primaryMethods = lbl_111_data_28 + 8;
    return object;
}

extern "C" void* fn_111_C464(ftClassInfo* object) {
    __ct__11ftClassInfoFb(object, false);
    MetaKnightMetadataPrefix* prefix = reinterpret_cast<MetaKnightMetadataPrefix*>(object);
    prefix->nullableMethods = lbl_111_data_5CD4;
    prefix->primaryMethods = lbl_111_data_5CD4 + 8;
    object->setClassInfo(Fighter_MetaKnight, object);
    return object;
}

extern "C" void* fn_111_C4BC(ftClassInfo* object, s16 deleting) {
    if (object) {
        MetaKnightMetadataPrefix* prefix = reinterpret_cast<MetaKnightMetadataPrefix*>(object);
        prefix->nullableMethods = lbl_111_data_5CD4;
        prefix->primaryMethods = lbl_111_data_5CD4 + 8;
        object->setClassInfo(Fighter_MetaKnight, &g_ftClassInfoNull);
        __dt__11ftClassInfoFv(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
