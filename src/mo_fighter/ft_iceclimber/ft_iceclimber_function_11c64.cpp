#pragma force_active on
typedef signed short s16;

struct Flags {
    unsigned char enabled : 1;
    unsigned char rest : 7;
};

extern "C" {
void fn_105_11938(void* self, void* arg);
s16* fn_105_12C6C(s16* destination, const s16* source);
void fn_105_11CF4(void* self, s16* value, void* arg);
}

extern "C" void fn_105_11C64(void* object, const s16* index, void* arg) {
    unsigned char* a = static_cast<unsigned char*>(object);
    unsigned char* sub = a + 0xC;
    if ((index[0] & 1) != 0) {
        Flags* flags = reinterpret_cast<Flags*>(sub + 5);
        bool enabled = flags->enabled;
        if (enabled == true && sub[6] == 0) {
            fn_105_11938(sub, arg);
        }
    }
    s16 local;
    fn_105_12C6C(&local, index);
    fn_105_11CF4(a + 4, &local, arg);
}
