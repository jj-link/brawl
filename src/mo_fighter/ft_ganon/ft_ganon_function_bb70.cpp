#include <types.h>
#pragma force_active on
extern "C" void fn_109_BB20(void*, void*);
extern "C" void fn_109_BFA8(s16*, const s16*);
extern "C" s32 fn_109_BC00(void*, const s16*, void*);
struct Entry {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char disabled;
};
extern "C" void fn_109_BB70(void* object, const s16* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    Entry* entry = reinterpret_cast<Entry*>(composite + 0xC);
    if ((index[0] & 1) != 0 &&
        (static_cast<unsigned int>(entry->flag ? 1 : 0) == 1U) &&
        entry->disabled == 0)
        fn_109_BB20(entry, argument);
    s16 operation;
    fn_109_BFA8(&operation, index);
    fn_109_BC00(composite + 4, &operation, argument);
}