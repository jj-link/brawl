#pragma force_active on
typedef signed short s16;
typedef unsigned char u8;

namespace {
struct FtZakoEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_126_911C(void* self, void* arg);
void fn_126_968C(s16* destination, const s16* source);
void fn_126_91FC(void* self, const s16* data, void* arg);
}

extern "C" void fn_126_916C(u8* self, const s16* src, void* arg) {
    s16 tmp[4];
    FtZakoEntry* entry = reinterpret_cast<FtZakoEntry*>(self + 0xC);
    if ((src[0] & 1) != 0) {
        if (entry->isEnabled() == true && entry->disabled == false) {
            fn_126_911C(entry, arg);
        }
    }
    fn_126_968C(tmp, src);
    fn_126_91FC(self + 4, tmp, arg);
}
