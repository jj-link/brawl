#pragma force_active on
struct Holder;
extern "C" void fn_2_85CC(Holder* self, int idx, int arg);

struct Inner {
    Holder* m_holder;
};

struct Outer {
    char pad[0xc];
    Inner* m_inner;
};

extern "C" void fn_1_6AF4(Outer* self, int arg) {
    fn_2_85CC(self->m_inner->m_holder, 0, arg);
}
