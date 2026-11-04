#include <so/so_module_accesser.h>
#pragma force_active on
struct Flag { unsigned char value; Flag() { __memclr(&value, 1); } };
struct Virt {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual int v22(); virtual void v23();
    virtual int v24();
};
extern "C" {
void fn_27_1DCC10(int, unsigned char*, soModuleAccesser*);
void fn_113_1DE6C(void*, unsigned char*, soModuleAccesser*);
void fn_113_1E224(void*, unsigned char*, soModuleAccesser*);
void fn_113_1E5D4(void*, unsigned char*, soModuleAccesser*);
void fn_113_1E820(void*, unsigned char*, soModuleAccesser*);
void fn_113_1E9F0(void*, unsigned char*, soModuleAccesser*);
void fn_113_1EB88(void*, unsigned char*, soModuleAccesser*);
void fn_113_1EDA8(void*, unsigned char*, soModuleAccesser*);
void fn_113_1F154(void*, unsigned char*, soModuleAccesser*);
void fn_113_1F304(void*, unsigned char*, soModuleAccesser*);
void fn_113_1F360(void*, unsigned char*, soModuleAccesser*);
void fn_113_1F530(void*, unsigned char*, soModuleAccesser*);
void fn_113_1F7F0(void*, unsigned char*, soModuleAccesser*);
void fn_113_1F944(void*, unsigned char*, soModuleAccesser*);
void fn_113_1FA18(void*, unsigned char*, soModuleAccesser*);
void fn_113_1FD38(void*, unsigned char*, soModuleAccesser*);
void fn_113_1F434(void*, unsigned char*, soModuleAccesser*);
void fn_113_1FF4C(void*, unsigned char*, soModuleAccesser*);
void fn_113_2020C(void*, unsigned char*, soModuleAccesser*);
void fn_113_2037C(void*, unsigned char*, soModuleAccesser*);
void fn_113_20510(void*, unsigned char*, soModuleAccesser*);
void fn_113_206A8(void*, unsigned char*, soModuleAccesser*);
void fn_113_20844(void*, unsigned char*, soModuleAccesser*);
void fn_113_20984(void*, unsigned char*, soModuleAccesser*);
void fn_113_1F054(void*, unsigned char*, soModuleAccesser*);
void fn_113_1EF84(void*, unsigned char*, soModuleAccesser*);
}
inline void call224(unsigned char* energies, soModuleAccesser* accesser) { Flag f; fn_113_1E224(&f, energies, accesser); }
extern "C" void fn_113_1DAB8(int kind, unsigned char* energies, soModuleAccesser* accesser) {
    Virt* module = *(Virt**)(*(char**)((char*)accesser + 0xd8) + 0x7c);
    if (module->v22() == 42) {
        module = *(Virt**)(*(char**)((char*)accesser + 0xd8) + 0x7c);
        module->v9();
    }
    if (kind <= 31) {
        fn_27_1DCC10(kind, energies, accesser);
        return;
    }
    switch (kind) {
    case 32: { Flag f; fn_113_1DE6C(&f, energies, accesser); break; }
    case 33: { Flag f; fn_113_1E224(&f, energies, accesser); break; }
    case 34: { Flag f; call224(energies, accesser); break; }
    case 35: { Flag f; fn_113_1E5D4(&f, energies, accesser); break; }
    case 36: { Flag f; fn_113_1E820(&f, energies, accesser); break; }
    case 37: { Flag f; fn_113_1E9F0(&f, energies, accesser); break; }
    case 38: { Flag f; fn_113_1EB88(&f, energies, accesser); break; }
    case 39: { Flag f; fn_113_1EDA8(&f, energies, accesser); break; }
    case 40: { Flag f; fn_113_1F154(&f, energies, accesser); break; }
    case 41: { Flag f; fn_113_1F304(&f, energies, accesser); break; }
    case 42: { Flag f; fn_113_1F360(&f, energies, accesser); break; }
    case 43: { Flag f; fn_113_1F530(&f, energies, accesser); break; }
    case 44: { Flag f; fn_113_1F7F0(&f, energies, accesser); break; }
    case 45: { Flag f; fn_113_1F944(&f, energies, accesser); break; }
    case 46: { Flag f; fn_113_1FA18(&f, energies, accesser); break; }
    case 47: { Flag f; fn_113_1FD38(&f, energies, accesser); break; }
    case 48: { Flag f; fn_113_1F434(&f, energies, accesser); break; }
    case 49: { Flag f; fn_113_1FF4C(&f, energies, accesser); break; }
    case 50: { Flag f; fn_113_2020C(&f, energies, accesser); break; }
    case 51: { Flag f; fn_113_2037C(&f, energies, accesser); break; }
    case 52: { Flag f; fn_113_20510(&f, energies, accesser); break; }
    case 53: { Flag f; fn_113_206A8(&f, energies, accesser); break; }
    case 54: { Flag f; fn_113_20844(&f, energies, accesser); break; }
    case 55: { Flag f; fn_113_20984(&f, energies, accesser); break; }
    case 56: { Flag f; fn_113_1F054(&f, energies, accesser); break; }
    case 57: { Flag f; fn_113_1EF84(&f, energies, accesser); break; }
    default: return;
    }
    Flag a;
    energies[0x11d] |= 0x80;
    Flag b;
    energies[0xfd] |= 0x80;
}