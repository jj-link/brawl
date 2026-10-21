#pragma force_active on
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;

extern "C" {
void fn_94_E470(void* p, void* arg);
s16* fn_94_EAC8(s16* destination, const s16* source);
s32 fn_94_E550(void* p, s16* s, void* arg);
}

struct Samus94Sub {
    u8 prefix[5];
    u8 enabled : 1;
    u8 otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};

extern "C" void fn_94_E4C0(void* object, const s16* source, void* arg) {
    u8* obj = static_cast<u8*>(object);
    Samus94Sub* sub = reinterpret_cast<Samus94Sub*>(obj + 0xC);
    if ((source[0] & 1) != 0) {
        if (sub->isEnabled() == true && sub->disabled == false) {
            fn_94_E470(sub, arg);
        }
    }
    s16 tmp;
    fn_94_EAC8(&tmp, source);
    fn_94_E550(obj + 4, &tmp, arg);
}
