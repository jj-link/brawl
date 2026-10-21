#pragma force_active on
extern "C" void fn_125_E0B4(void* self, void* arg);
extern "C" void fn_125_E53C(short* dest, const short* src);
extern "C" int fn_125_E194(void* self, short* src, void* arg);

struct WolfFlags {
    unsigned char pad[5];
    unsigned char on : 1;
    unsigned char rest : 7;
    bool disabled;
};

extern "C" void fn_125_E104(unsigned char* self, short* src, void* arg) {
    WolfFlags* sub = reinterpret_cast<WolfFlags*>(self + 0xC);
    if (src[0] & 1) {
        bool on = sub->on;
        if (on == true && sub->disabled == false) {
            fn_125_E0B4(sub, arg);
        }
    }
    short tmp;
    fn_125_E53C(&tmp, src);
    fn_125_E194(self + 4, &tmp, arg);
}
