#pragma force_active on
extern "C" {
short* fn_113_1D4E4(short* destination, const short* source);
int fn_113_1D08C(void* object, short* source, void* argument);
void fn_113_20B38(void* entry, void* accesser);
}

struct PikminFlags {
    unsigned char prefix[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char after;
};

extern "C" void fn_113_1CFFC(unsigned char* self, const short* source, void* argument) {
    PikminFlags* sub = reinterpret_cast<PikminFlags*>(self + 0xC);
    short tmp;
    if ((*source & 1) != 0) {
        bool enabled = sub->flag;
        if (enabled == true && sub->after == 0) {
            fn_113_20B38(sub, argument);
        }
    }
    fn_113_1D4E4(&tmp, source);
    fn_113_1D08C(self + 4, &tmp, argument);
}
