#pragma force_active on
class ModuleBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(int x, unsigned int d, bool flag, unsigned int b);
};

extern "C" void fn_41_34AE8(void* self, char* em, unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    char* holder = *(char**)(em + 0xd8);
    ModuleBase* mod = *(ModuleBase**)(holder + 0x4c);
    mod->vf2(0, d, a == 0, b);
}
