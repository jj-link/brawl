#pragma force_active on
typedef unsigned short u16;

extern "C" {
extern void fn_80062B78(char* self);

void fn_80062B44(char* self, void* p, short v, int flag) {
    *(void**)(self + 0x50) = p;
    if (p == 0) {
        return;
    }
    {
        u16 f = *(u16*)(self + 0x56);
        *(short*)(self + 0x54) = v;
        f &= 0xFFFE;
        *(u16*)(self + 0x56) = f;
        if (flag != 0) {
            f |= 1;
            *(u16*)(self + 0x56) = f;
        }
    }
    fn_80062B78(self);
}
}
