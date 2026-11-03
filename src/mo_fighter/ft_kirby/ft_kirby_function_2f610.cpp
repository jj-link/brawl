#pragma force_active on
struct Accesser;
class Class_CD28 {
public:
    virtual void fn_96_28D0();
    virtual void fn_96_2331C();
    virtual void fn_96_23D84();
    virtual void fn_96_23D7C(int, Accesser*);
    virtual void fn_96_23D74();
    virtual void fn_96_23D6C();
    virtual void fn_96_23D64();
    virtual void fn_96_23D5C();
    virtual void fn_96_23D54();
    virtual void fn_96_23D4C();
    virtual void fn_96_23D44();
    virtual void fn_96_23D3C();
    virtual void fn_96_23D34();
    virtual void fn_96_23D2C();
    virtual void fn_96_23CDC();
    virtual void fn_96_23D24();
    virtual int fn_96_23D14();
    virtual void fn_96_23D04();
    virtual void fn_96_23CF4(unsigned long);
    virtual void fn_96_23CE4(unsigned long);
};
struct Modules {
    char pad[0x64];
    Class_CD28* work;
    char pad68[8];
    Class_CD28* status;
};
struct Accesser {
    char pad[0xd8];
    Modules* modules;
};
struct Self {
    char pad[0x60];
    Accesser* accesser;
};
extern "C" void fn_27_1DB0F0(Self*, int*, Accesser*, void*, int);
extern "C" void fn_96_2F610(Self* self, int* event, Accesser* accesser, void* object, int arg) {
    switch (*event) {
    case 0x83a:
        if (accesser->modules->status->fn_96_23D14() == 0) {
            self->accesser->modules->status->fn_96_23D7C(1, self->accesser);
        } else if (accesser->modules->status->fn_96_23D14() == 1) {
            accesser->modules->status->fn_96_23D7C(2, self->accesser);
        } else {
            accesser->modules->status->fn_96_23D7C(3, self->accesser);
        }
        break;
    case 0x838:
        accesser->modules->work->fn_96_23CE4(0x22000002);
        accesser->modules->work->fn_96_23CF4(0x22000001);
        break;
    case 0x839:
        accesser->modules->work->fn_96_23CF4(0x22000002);
        accesser->modules->work->fn_96_23CF4(0x22000001);
        break;
    }
    fn_27_1DB0F0(self, event, accesser, object, arg);
}