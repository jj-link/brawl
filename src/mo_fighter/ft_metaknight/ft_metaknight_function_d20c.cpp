#include <types.h>
#include <ft/ft_extend_param_accesser.h>
#pragma force_active on

extern "C" const u8 lbl_111_data_5E50[];

// MetaKnight "metadata" blob layout shared with fn_111_C41C: the first word is
// the pointer to the primary method table inside that blob.
struct MetaKnightMetadata {
    const u8* primaryMethods;
    u32 baseState;
    const u8* nullableMethods;
};

extern "C" void fn_111_D20C(MetaKnightMetadata* object) {
    object->primaryMethods = lbl_111_data_5E50;
}
