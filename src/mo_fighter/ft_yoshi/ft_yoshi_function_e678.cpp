#pragma force_active on
typedef short s16;
typedef int s32;

struct YoshiEntry {
    unsigned char padding[5];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    unsigned char disabled;
    bool isEnabled() const { return enabled; }
};

extern "C" void fn_95_E628(void*, void*);
extern "C" s16* fn_95_ED68(s16*, const s16*);
extern "C" s32 fn_95_E708(void*, s16*, void*);

extern "C" void fn_95_E678(void* object, const s16* index, void* argument) {
    unsigned char* composite = (unsigned char*)object;
    YoshiEntry* entry = (YoshiEntry*)(composite + 0xC);

    if ((index[0] & 1) != 0 &&
        entry->isEnabled() == true &&
        entry->disabled == false) {
        fn_95_E628(entry, argument);
    }

    s16 operation[4];
    fn_95_ED68(operation, index);
    fn_95_E708(composite + 4, operation, argument);
}
