#pragma force_active on
extern "C" {
short* fn_95_ED68(short* destination, const short* source);
void fn_95_E710(void* obj, int arg);
void fn_95_E7F0(void* obj, short* data, int arg);
}

struct YoshiSub {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char b6;
    bool isFlag() const { return flag; }
};

extern "C" void fn_95_E760(unsigned char* self, const short* src, int arg) {
    short buf[4];
    YoshiSub* sub = reinterpret_cast<YoshiSub*>(self + 0xC);
    if ((src[0] & 1) != 0 && sub->isFlag() == true && sub->b6 == 0) {
        fn_95_E710(sub, arg);
    }
    fn_95_ED68(buf, src);
    fn_95_E7F0(self + 4, buf, arg);
}
