#include <revolution/FA/FA.h>
#pragma force_active on

extern FAHandle* fn_803EB644(const char*, const char*);

FAHandle* FAFopen(const char* filepath, const char* mode) {
    FAHandle* handle = fn_803EB644(filepath, mode);
    if (handle == NULL)
        return NULL;
    return handle;
}
