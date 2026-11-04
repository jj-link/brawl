#pragma force_active on
// The classes and the object this function's exception table needs, written by decomp-orchestrator.
// Keep them and write the rest of the function so its code matches. Add members as the code needs.

extern "C" void fn_80281ED8(void* p);

class Class_8008080C {
public:
    Class_8008080C() {}
    ~Class_8008080C() {}
};

extern "C" char lbl_80488988[];  // the vtable of Class_80312FD8, under its name in the game
struct Vtable_Class_80312FD8 {
    void* vtable;
    Vtable_Class_80312FD8() {}
};
class Class_80312FD8 : public Class_8008080C, public Vtable_Class_80312FD8 {
public:
    Class_80312FD8();
    ~Class_80312FD8() {}

    char pad4[2];
    short unk6;
    int unk8;
    short unkC;
    char padE[2];
    int unk10;
};

Class_80312FD8::Class_80312FD8() {
    unk6 = 1;
    vtable = lbl_80488988;
    unk8 = -0x2F;
    unkC = 0;
    unk10 = 0;
    fn_80281ED8(&unk8);
}
