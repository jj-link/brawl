#pragma force_active on
typedef unsigned char u8;

struct Ret {
    u8 pad[2];
    u8 idx;
};

struct Base {
    u8 pad[0x3C];
};

#define V(n) virtual void f##n();
struct Self : Base {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36)
    virtual Ret* f39();
    u8 pad1[0x57 - 0x40];
    u8 state;
};
#undef V

extern "C" void fn_800E1384(void*);
extern "C" int g_IfMngr;
extern "C" int g_IfAdvMngr;

extern "C" void fn_27_23CEEC(Self* self) {
    if (self->state != 6) {
        if (g_IfMngr != 0) {
            Ret* r = self->f39();
            fn_800E1384((void*)*(int*)((char*)g_IfMngr + (r->idx << 2) + 0x4C));
        }
        if (g_IfAdvMngr != 0) {
            Ret* r = self->f39();
            fn_800E1384((void*)*(int*)((char*)g_IfAdvMngr + (r->idx << 2) + 0xE8));
        }
    }
}
