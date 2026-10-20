#pragma force_active on
extern "C" {
void fn_101_10AF0(void*, void*);
void fn_101_10CC0(short*, const short*);
int fn_101_10BD0(void*, short*, void*);
}

struct NessSubBits {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char tail;
};

extern "C" void fn_101_10B40(unsigned char* self, const short* param, void* accesser) {
    NessSubBits* sub = reinterpret_cast<NessSubBits*>(self + 0xC);
    if ((param[0] & 8) != 0) {
        bool flag = sub->flag;
        if (flag == true && sub->tail == 0) {
            fn_101_10AF0(sub, accesser);
        }
    }
    short local;
    fn_101_10CC0(&local, param);
    fn_101_10BD0(self + 4, &local, accesser);
}
