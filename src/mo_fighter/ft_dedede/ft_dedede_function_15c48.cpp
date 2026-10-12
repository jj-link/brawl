#pragma section data_type ".data$dedede15C48" ".bss"

#include <so/so_module_accesser.h>

// Each kinetic mode has a distinct stateless reset policy. Its temporary is
// passed as the first argument of the policy's reset operation.
template <int Kind> struct DededeResetPolicy {};

extern "C" {
void fn_27_1DCC10(int, unsigned char*, soModuleAccesser*);
void fn_117_15DF0(void*, unsigned char*, soModuleAccesser*);
void fn_117_16014(void*, unsigned char*, soModuleAccesser*);
void fn_117_16200(const void*, unsigned char*, soModuleAccesser*);
void fn_117_1640C(void*, unsigned char*, soModuleAccesser*);
void fn_117_164F4(void*, unsigned char*, soModuleAccesser*);
void fn_117_16660(const void*, unsigned char*, soModuleAccesser*);
void fn_117_16850(void*, unsigned char*, soModuleAccesser*);
void fn_117_16AB4(void*, unsigned char*, soModuleAccesser*);
void fn_117_16D18(void*, unsigned char*, soModuleAccesser*);
void fn_117_16E98(void*, unsigned char*, soModuleAccesser*);
void fn_117_16F6C(void*, unsigned char*, soModuleAccesser*);
void fn_117_17178(void*, unsigned char*, soModuleAccesser*);
void fn_117_17408(void*, unsigned char*, soModuleAccesser*);
void fn_117_17558(void*, unsigned char*, soModuleAccesser*);
void fn_117_177CC(const void*, unsigned char*, soModuleAccesser*);
}

extern "C" void fn_117_15C48(int kind, unsigned char* energies, soModuleAccesser* accesser) {
    if (kind <= 31) {
        fn_27_1DCC10(kind, energies, accesser);
    } else {
        switch (kind) {
        case 32: { DededeResetPolicy<32> policy = {}; fn_117_15DF0(&policy, energies, accesser); break; }
        case 33: { DededeResetPolicy<33> policy = {}; fn_117_16014(&policy, energies, accesser); break; }
        case 34: { DededeResetPolicy<34> policy = {}; fn_117_16200(&policy, energies, accesser); break; }
        case 35: { DededeResetPolicy<35> policy = {}; fn_117_1640C(&policy, energies, accesser); break; }
        case 36: { DededeResetPolicy<36> policy = {}; fn_117_164F4(&policy, energies, accesser); break; }
        case 37: { DededeResetPolicy<37> policy = {}; fn_117_16660(&policy, energies, accesser); break; }
        case 38: { DededeResetPolicy<38> policy = {}; fn_117_16850(&policy, energies, accesser); break; }
        case 39: { DededeResetPolicy<39> policy = {}; fn_117_16AB4(&policy, energies, accesser); break; }
        case 40: { DededeResetPolicy<40> policy = {}; break; }
        case 41: { DededeResetPolicy<41> policy = {}; fn_117_16D18(&policy, energies, accesser); break; }
        case 42: { DededeResetPolicy<42> policy = {}; accesser->getKineticModule().unableEnergyAll(); break; }
        case 43: { DededeResetPolicy<43> policy = {}; fn_117_16E98(&policy, energies, accesser); break; }
        case 44: { DededeResetPolicy<44> policy = {}; fn_117_16F6C(&policy, energies, accesser); break; }
        case 45: { DededeResetPolicy<45> policy = {}; fn_117_17178(&policy, energies, accesser); break; }
        case 46: { DededeResetPolicy<46> policy = {}; fn_117_17408(&policy, energies, accesser); break; }
        case 47: { DededeResetPolicy<47> policy = {}; fn_117_17558(&policy, energies, accesser); break; }
        case 48: { DededeResetPolicy<48> policy = {}; fn_117_177CC(&policy, energies, accesser); break; }
        }
    }
}
