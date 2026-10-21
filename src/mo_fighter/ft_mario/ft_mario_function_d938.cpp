#pragma force_active on
extern "C" {
void fn_91_D8E8(void*, void*);
void fn_91_DAB8(short*, const short*);
void fn_91_D9C8(void*, short*, void*);
}

struct FtMarioSub {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char next;
};

extern "C" void fn_91_D938(unsigned char* self, const short* src, void* arg) {
    short tmp[4];
    FtMarioSub* p = reinterpret_cast<FtMarioSub*>(self + 0xc);
    if (src[0] & 8) {
        if ((bool)p->flag == 1 && p->next == 0) {
            fn_91_D8E8(p, arg);
        }
    }
    fn_91_DAB8(tmp, src);
    fn_91_D9C8(self + 4, tmp, arg);
}
