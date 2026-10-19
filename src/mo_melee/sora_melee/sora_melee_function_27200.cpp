#pragma force_active on
class fn27Sub {
public:
    virtual void f0();
    virtual void* f1(void* b);
};

class fn27Obj {
public:
    char pad[0x28];
    fn27Sub* m_sub;
};

extern "C" void fn_27_2EFC0(void* r3, void* a);

extern "C" {
void fn_27_27200(fn27Obj* self, void* a, void* b) {
    fn_27_2EFC0(self->m_sub->f1(b), a);
}
}
