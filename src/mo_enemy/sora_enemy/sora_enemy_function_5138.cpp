#include <types.h>
#pragma force_active on

extern "C" {
struct Entry {
    u32* data;
    s32 size;
};

void* getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(void* acc, u32 id, u32 index);

bool fn_41_5138(char* self, u32 kind) {
    if (kind == 0) {
        return true;
    }
    Entry* p = (Entry*)getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(self + 0xdc, 0xA800, 0);
    if (p != NULL) {
        for (s32 i = 0; i < p->size; i++) {
            if (p->data[i] == kind) {
                return true;
            }
        }
    }
    return false;
}
}
