#pragma force_active on
typedef short s16;
typedef int s32;

extern "C" {
void fn_93_E4C4(void* object, void* arg);
s16* fn_93_E94C(s16* destination, const s16* source);
void fn_93_E5A4(void* object, const s16* value, void* arg);
}

struct LinkFlags {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
};

extern "C" void fn_93_E514(void* self, const s16* src, void* arg) {
    unsigned char* composite = static_cast<unsigned char*>(self) + 0xC;
    if ((src[0] & 1) != 0) {
        LinkFlags* flags = reinterpret_cast<LinkFlags*>(composite);
        bool enabled = flags->enabled;
        if (enabled == true && flags->disabled == false) {
            fn_93_E4C4(composite, arg);
        }
    }

    s16 local;
    fn_93_E94C(&local, src);
    fn_93_E5A4(static_cast<unsigned char*>(self) + 4, &local, arg);
}
