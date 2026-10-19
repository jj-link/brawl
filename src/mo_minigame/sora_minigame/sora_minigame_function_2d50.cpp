#pragma force_active on
extern "C" void fn_80099994(void* p, int flag);
extern "C" void fn_20_120(void* p, int flag);
extern "C" void __dl__FPv(void* p);

struct Obj {
    char m_base[8];
    char m_member[16];
};

extern "C" Obj* fn_20_2D50(Obj* self, int flag) {
    if (self != 0) {
        fn_80099994(self->m_member, 0);
        fn_20_120(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
