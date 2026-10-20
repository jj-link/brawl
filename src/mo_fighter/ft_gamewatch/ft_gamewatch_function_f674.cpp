#pragma force_active on
typedef signed short s16;

struct GWFlags {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char next;
};

extern "C" void fn_107_F624(unsigned char* a, void* b);
extern "C" void fn_107_FD64(s16* dst, const s16* src);
extern "C" void fn_107_F704(unsigned char* a, s16* b, void* c);

extern "C" void fn_107_F674(unsigned char* self, const s16* p, void* arg) {
    s16 buf[2];
    GWFlags* obj = reinterpret_cast<GWFlags*>(self + 0xC);
    if ((p[0] & 1) != 0) {
        unsigned int bit = (obj->flag != 0);
        if (bit == 1 && obj->next == 0) {
            fn_107_F624(reinterpret_cast<unsigned char*>(obj), arg);
        }
    }
    fn_107_FD64(buf, p);
    fn_107_F704(self + 4, buf, arg);
}
