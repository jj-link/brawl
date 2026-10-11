#include <ft/ft_extend_param_accesser.h>
#include <types.h>

typedef ftExtendParamAccesserEx<3999, 27, 24999, 8> ftMetaKnightExtendParamAccesserEx;

// A base-subobject destructor call uses mode 0; an explicit C++ complete-object
// destructor expression uses mode -1 instead.
extern "C" void* __dt__21ftExtendParamAccesserFv(ftExtendParamAccesser* object, s16 deleting);

extern "C" void* fn_111_82FC(ftMetaKnightExtendParamAccesserEx* object, int deleting) {
    if (object != 0) {
        object->ftMetaKnightExtendParamAccesserEx::~ftMetaKnightExtendParamAccesserEx();
        if (static_cast<s16>(deleting) > 0) {
            operator delete(object);
        }
    }
    return object;
}

// Retain the unreferenced destructor that was part of the original REL.
#pragma force_active on
extern "C" void* fn_111_835C(ftExtendParamAccesser* object, int deleting) {
    if (object != 0) {
        __dt__21ftExtendParamAccesserFv(object, 0);
        if (static_cast<s16>(deleting) > 0) {
            operator delete(object);
        }
    }
    return object;
}
