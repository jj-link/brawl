#pragma force_active on
extern "C" void fn_92_C300(void* a, void* b);
extern "C" void fn_92_C870(short* dst, const short* src);
extern "C" void fn_92_C3E0(void* a, short* b, void* c);

struct DonkeyFlags {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char pad2;
};

extern "C" void fn_92_C350(void* self, short* src, void* arg) {
    unsigned char* base = static_cast<unsigned char*>(self);
    DonkeyFlags* sub = reinterpret_cast<DonkeyFlags*>(base + 0xC);
    if ((src[0] & 1) != 0) {
        bool f = sub->flag;
        if (f == true && sub->pad2 == 0) {
            fn_92_C300(sub, arg);
        }
    }
    short tmp;
    fn_92_C870(&tmp, src);
    fn_92_C3E0(base + 4, &tmp, arg);
}
