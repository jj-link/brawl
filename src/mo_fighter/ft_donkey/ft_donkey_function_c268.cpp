#pragma force_active on
extern "C" void fn_92_C218(void* object, void* argument);
extern "C" void fn_92_C870(short* destination, const short* source);
extern "C" void fn_92_C2F8(void* object, const short* value, void* argument);

struct DonkeySub {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char next;
};

extern "C" void fn_92_C268(unsigned char* self, const short* source, void* argument) {
    short buffer;
    DonkeySub* sub = reinterpret_cast<DonkeySub*>(self + 0xC);
    if ((source[0] & 1) != 0 && static_cast<bool>(sub->flag) == true && sub->next == 0) {
        fn_92_C218(sub, argument);
    }
    fn_92_C870(&buffer, source);
    fn_92_C2F8(self + 4, &buffer, argument);
}
