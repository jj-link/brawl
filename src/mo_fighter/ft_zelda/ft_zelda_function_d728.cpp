#pragma force_active on

typedef signed short s16;
typedef int s32;

extern "C" {
void fn_104_D6D8(void* entry, void* argument);
s16* fn_104_DC48(s16* destination, const s16* source);
s32 fn_104_D7B8(void* object, const s16* index, void* argument);
}

struct ZeldaTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};

extern "C" void fn_104_D728(unsigned char* object, const s16* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    ZeldaTraversalEntry* entry = reinterpret_cast<ZeldaTraversalEntry*>(composite + 0xC);

    if ((index[0] & 1) != 0 &&
        entry->isEnabled() == true &&
        entry->disabled == false)
        fn_104_D6D8(entry, argument);

    s16 operation;
    fn_104_DC48(&operation, index);
    fn_104_D7B8(composite + 4, &operation, argument);
}
