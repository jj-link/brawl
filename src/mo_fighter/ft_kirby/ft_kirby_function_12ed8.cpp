#pragma force_active on
typedef short s16;
typedef unsigned char u8;

extern "C" {
void fn_96_21420(void* obj, void* arg);
s16* fn_96_13310(s16* destination, const s16* source);
int fn_96_12F68(void* self, s16* data, void* arg);
}

struct KirbyFlagEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};

extern "C" void fn_96_12ED8(u8* self, s16* source, void* arg) {
    s16 buf[4];
    KirbyFlagEntry* entry = reinterpret_cast<KirbyFlagEntry*>(self + 0xC);
    if ((source[0] & 1) != 0 && entry->isEnabled() == true && entry->disabled == false) {
        fn_96_21420(entry, arg);
    }
    fn_96_13310(buf, source);
    fn_96_12F68(self + 4, buf, arg);
}
