#include <types.h>
#pragma force_active on

extern "C" void fn_27_34CC40(s16*, const s16*);
extern "C" void fn_27_34CC4C(void*, const s16*, void*);

union ShortStorage {
    s16 value;
    s32 alignment;
};

extern "C" void fn_27_34CAD8(void* self, void* arg, const s16* value) {
    ShortStorage result;
    ShortStorage input;
    ShortStorage output;

    input.value = *value;
    fn_27_34CC40(&result.value, &input.value);
    output.value = result.value;
    fn_27_34CC4C((char*)self + 8, &output.value, arg);
}
