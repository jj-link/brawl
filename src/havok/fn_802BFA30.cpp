#pragma force_active on
// The classes and the object this function's exception table needs, written by decomp-orchestrator.
// Keep them and write the rest of the function so its code matches. Add members as the code needs.

extern "C" void fn_802BE7C4(void*, void*, void*, void*, void*);

extern "C" char lbl_80487178[];  // the vtable of Class_802A3938, under its name in the game
class Class_802A3938 {
public:
    void* vtable;
    char flag;
    int unk8;
    Class_802A3938(int a) : flag(0), unk8(a) { vtable = (void*)lbl_80487178; }
    ~Class_802A3938() {}
};

extern "C" void fn_802BFA30(void* a1, void* a2, void* a3, void* a4, void* a5) {
    Class_802A3938 local0((int)a5);
    fn_802BE7C4(a1, a3, a2, a4, &local0);
}
