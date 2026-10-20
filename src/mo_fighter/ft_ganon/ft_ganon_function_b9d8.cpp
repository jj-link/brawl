#pragma force_active on
typedef signed short s16;
typedef int s32;

extern "C" void fn_109_B988(void* a, void* b);
extern "C" void fn_109_BFA8(s16* destination, const s16* source);
extern "C" s32 fn_109_BA68(void* a, s16* b, void* c);

struct Ganon109Flags {
    unsigned char pad[5];
    unsigned char enabled : 1;
    unsigned char rest : 7;
    unsigned char unk6;
};

extern "C" void fn_109_B9D8(void* self, const s16* source, void* arg) {
    Ganon109Flags* p = (Ganon109Flags*)((unsigned char*)self + 0xC);
    s16 local[4];

    if ((source[0] & 1) != 0) {
        bool e = p->enabled;
        if (e == true && p->unk6 == 0) {
            fn_109_B988(p, arg);
        }
    }

    fn_109_BFA8(local, source);
    fn_109_BA68((unsigned char*)self + 4, local, arg);
}
