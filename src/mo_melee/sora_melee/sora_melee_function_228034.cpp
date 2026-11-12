#include <types.h>
#pragma force_active on
struct Record { float value; u8 pad[0x50]; s32 result; u32 pad58; u32 target; u32 output; };
extern "C" void fn_27_22811C(void*, void*, void*);
extern "C" s32 fn_27_228034(u8* base, u32 target, void* arg, u32* out) {
    if (target == 0) return 0;
    s32 offset;
    Record* records;
    s32 index;
    index = 0;
    offset = 0;
    for (s32 count = 3; count != 0; --count) {
        records = *(Record**)(base + 4);
        if (*(u32*)((u8*)records + offset + 0x5C) == target) {
            records[index].result = (s32)((float)base[8] * records[index].value);
            fn_27_22811C(base, &(*(Record**)(base + 4))[index], arg);
            *out = (*(Record**)(base + 4))[index].output;
            return 1;
        }
        offset += 0x64;
        ++index;
    }
    return 0;
}