#pragma force_active on
typedef short s16;

struct SamusSub {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char next;
};

extern "C" void fn_94_E388(void* p, void* q);
extern "C" s16* fn_94_EAC8(s16* dst, const s16* src);
extern "C" void fn_94_E468(void* p, s16* src, void* q);

extern "C" void fn_94_E3D8(unsigned char* self, const s16* src, void* arg) {
    SamusSub* sub = reinterpret_cast<SamusSub*>(self + 0xC);
    if ((src[0] & 1) != 0) {
        bool f = sub->flag;
        if (f == true && sub->next == 0) {
            fn_94_E388(sub, arg);
        }
    }
    s16 buf[4];
    fn_94_EAC8(buf, src);
    fn_94_E468(self + 4, buf, arg);
}
