#pragma force_active on
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;

namespace {
struct YoshiFlagEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_95_E8E0(void* self, void* arg);
s16* fn_95_ED68(s16* destination, const s16* source);
s32 fn_95_E9C0(void* self, const s16* data, void* arg);
}

extern "C" void fn_95_E930(u8* self, s16* source, void* arg) {
    YoshiFlagEntry* entry = reinterpret_cast<YoshiFlagEntry*>(self + 0xC);
    s16 local[4];

    if (source[0] & 1) {
        if (entry->isEnabled() == true && entry->disabled == false) {
            fn_95_E8E0(entry, arg);
        }
    }

    fn_95_ED68(local, source);
    fn_95_E9C0(self + 4, local, arg);
}
