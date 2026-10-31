#pragma force_active on
struct soModuleAccesser;

template <int Kind> struct WarioResetPolicy {};

extern "C" {
void fn_27_1DCC10(int, unsigned char*, soModuleAccesser*);
void fn_110_13CF0(void*, unsigned char*, soModuleAccesser*);
void fn_110_13E34(void*, unsigned char*, soModuleAccesser*);
void fn_110_14054(void*, unsigned char*, soModuleAccesser*);
void fn_110_14158(void*, unsigned char*, soModuleAccesser*);
void fn_110_142A0(void*, unsigned char*, soModuleAccesser*);
void fn_110_143E4(void*, unsigned char*, soModuleAccesser*);
void fn_110_14624(void*, unsigned char*, soModuleAccesser*);
void fn_110_147B8(void*, unsigned char*, soModuleAccesser*);
void fn_110_149D8(void*, unsigned char*, soModuleAccesser*);
}

extern "C" void fn_110_13BF0(int kind, unsigned char* energies,
                           soModuleAccesser* accesser)
{
    if (kind <= 31) {
        fn_27_1DCC10(kind, energies, accesser);
    } else {
        switch (kind) {
        case 32: {
            WarioResetPolicy<32> policy = {};
            fn_110_13CF0(&policy, energies, accesser);
            break;
        }
        case 33: {
            WarioResetPolicy<33> policy = {};
            fn_110_13E34(&policy, energies, accesser);
            break;
        }
        case 34: {
            WarioResetPolicy<34> policy = {};
            fn_110_14054(&policy, energies, accesser);
            break;
        }
        case 35: {
            WarioResetPolicy<35> policy = {};
            fn_110_14158(&policy, energies, accesser);
            break;
        }
        case 36: {
            WarioResetPolicy<36> policy = {};
            fn_110_142A0(&policy, energies, accesser);
            break;
        }
        case 37: {
            WarioResetPolicy<37> policy = {};
            fn_110_143E4(&policy, energies, accesser);
            break;
        }
        case 38: {
            WarioResetPolicy<38> policy = {};
            fn_110_14624(&policy, energies, accesser);
            break;
        }
        case 39: {
            WarioResetPolicy<39> policy = {};
            fn_110_147B8(&policy, energies, accesser);
            break;
        }
        case 40: {
            WarioResetPolicy<40> policy = {};
            fn_110_149D8(&policy, energies, accesser);
            break;
        }
        }
    }
}
