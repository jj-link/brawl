#pragma force_active on
typedef short s16;

struct FlagBlock {
    unsigned char pad[5];
    unsigned char enabled : 1;
    unsigned char rest : 7;
    unsigned char next;
};

extern "C" void fn_115_D0C4(void* self, int arg);
extern "C" void fn_115_D71C(s16* destination, const s16* source);
extern "C" int fn_115_D1A4(void* self, s16* source, int arg);

extern "C" void fn_115_D114(unsigned char* self, const s16* source, int arg) {
    FlagBlock* p = reinterpret_cast<FlagBlock*>(self + 0xC);
    if ((source[0] & 1) != 0) {
        bool flag = p->enabled;
        if (flag == true && p->next == 0) {
            fn_115_D0C4(p, arg);
        }
    }
    s16 tmp[3];
    fn_115_D71C(tmp, source);
    fn_115_D1A4(self + 4, tmp, arg);
}
