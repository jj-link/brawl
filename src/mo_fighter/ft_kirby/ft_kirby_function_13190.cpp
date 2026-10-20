#pragma force_active on
typedef signed short s16;

struct KirbyElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" {
void fn_96_13140(unsigned char* object, void* arg);
s16* fn_96_13310(s16* destination, const s16* source);
void fn_96_13220(unsigned char* object, s16* source, void* arg);
}

extern "C" void fn_96_13190(unsigned char* object, const s16* source, void* arg) {
    unsigned char* sub = object + 0xC;
    s16 local;
    if (source[0] & 8) {
        bool enabled = reinterpret_cast<KirbyElementFlags*>(sub + 5)->enabled;
        if (enabled == true && sub[6] == 0) {
            fn_96_13140(sub, arg);
        }
    }
    fn_96_13310(&local, source);
    fn_96_13220(object + 4, &local, arg);
}
