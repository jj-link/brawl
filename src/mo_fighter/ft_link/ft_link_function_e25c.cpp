#pragma force_active on
typedef signed short s16;
typedef int s32;

struct LinkEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};

extern "C" void fn_93_E20C(void* a, void* b);
extern "C" s16* fn_93_E94C(s16* destination, const s16* source);
extern "C" s32 fn_93_E2EC(void* a, s16* b, void* c);

extern "C" void fn_93_E25C(unsigned char* self, const s16* source, void* arg) {
    LinkEntry* entry = reinterpret_cast<LinkEntry*>(self + 0xC);
    if ((source[0] & 1) != 0) {
        if (entry->isEnabled() == true && entry->disabled == false) {
            fn_93_E20C(entry, arg);
        }
    }

    s16 local[4];
    fn_93_E94C(local, source);
    fn_93_E2EC(self + 4, local, arg);
}
