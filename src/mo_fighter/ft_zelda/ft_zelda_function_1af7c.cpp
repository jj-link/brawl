#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned int);
    virtual void slot5(int, unsigned int);
};
struct Enum { char pad[0x64]; Object_vptr_0* work; };
struct Access { char pad[0xd8]; Enum* e; };
struct Self { char pad[0x60]; Access* access; };
struct Arg { char pad[0xc]; int value; char pad2[0x13]; unsigned char a; unsigned char b; };
extern "C" void fn_27_135EDC(void*, void*);
extern "C" void fn_104_1AF7C(Self* self, Arg* arg) {
    fn_27_135EDC(self, arg);
    Object_vptr_0* work = self->access->e->work;
    int n = work->slot4(0x20000000);
    if (n < 8) {
        work->slot5(arg->value, n + 0x20000001);
        work->slot5(arg->a, n + 0x20000009);
        work->slot5(arg->b, n + 0x20000011);
        n++;
    }
    work->slot5(n, 0x20000000);
}