#pragma force_active on
typedef short s16;

extern "C" {
void fn_94_E640(void* obj, void* arg);
s16* fn_94_EAC8(s16* destination, const s16* source);
void fn_94_E720(void* obj, s16* data, void* arg);
}

struct Sub {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char other;
};

extern "C" void fn_94_E690(unsigned char* self, const s16* src, void* arg) {
    s16 local[4];
    Sub* sub = reinterpret_cast<Sub*>(self + 0xC);

    if ((src[0] & 1) != 0 && (bool)sub->flag == true && sub->other == 0) {
        fn_94_E640(sub, arg);
    }

    fn_94_EAC8(local, src);
    fn_94_E720(self + 4, local, arg);
}
