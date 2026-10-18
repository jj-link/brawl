#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

namespace {
struct DededeArticlePointerAccesser {
    u8 prefix[0x18];
    u32 indexBase;      // 0x18: first index served by the pointer table
    u8 gap[0xCC - 0x1C];
    void* tables[1];    // 0xCC: inline, variable-length pointer table
};
} // namespace

extern "C" {

void* fn_117_18018(DededeArticlePointerAccesser* self, soModuleAccesser* accesser, int index) {
    return self->tables[index - self->indexBase];
}
}
