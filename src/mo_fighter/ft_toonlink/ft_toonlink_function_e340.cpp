#pragma force_active on
typedef short s16;
typedef int s32;

namespace {
struct Ft121Entry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
}

extern "C" void fn_121_E2F0(void* object, void* arg);
extern "C" void fn_121_E948(s16* destination, const s16* source);
extern "C" void fn_121_E3D0(void* object, const s16* data, void* arg);

extern "C" void fn_121_E340(void* object, const s16* flags, void* arg) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    Ft121Entry* entry = reinterpret_cast<Ft121Entry*>(composite + 0xC);
    s16 tmp[2];

    if ((*flags & 1) != 0) {
        if (entry->isEnabled() == true && entry->disabled == false) {
            fn_121_E2F0(entry, arg);
        }
    }

    fn_121_E948(tmp, flags);
    fn_121_E3D0(composite + 4, tmp, arg);
}
