#pragma force_active on
typedef signed short s16;
typedef unsigned char u8;

namespace {
struct FalcoEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_108_DD50(void* entry, void* argument);
void fn_108_E490(s16* destination, const s16* source);
void fn_108_DE30(void* object, s16* local, void* argument);
}

extern "C" void fn_108_DDA0(u8* self, const s16* source, void* argument) {
    FalcoEntry* entry = reinterpret_cast<FalcoEntry*>(self + 0xC);
    s16 local[4];
    if ((source[0] & 1) != 0 && entry->isEnabled() == true && entry->disabled == false) {
        fn_108_DD50(entry, argument);
    }
    fn_108_E490(local, source);
    fn_108_DE30(self + 4, local, argument);
}
