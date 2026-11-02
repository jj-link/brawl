#pragma force_active on
struct soModuleAccesser;

// Each case passes a stateless policy object; its one zeroed byte is the
// temporary the original stores on the stack.
template <int Kind> struct ResetPolicy {};

extern "C" {
void fn_27_1DCC10(int, unsigned char*, soModuleAccesser*);
void fn_27_31A1D8(ResetPolicy<32>*);
void fn_27_31A3D0(ResetPolicy<33>*);
void fn_27_31A5BC(ResetPolicy<34>*);
void fn_27_31A79C(ResetPolicy<35>*);
}

extern "C" void fn_27_31A13C(int kind, unsigned char* energies, soModuleAccesser* accesser) {
    if (kind <= 31) {
        fn_27_1DCC10(kind, energies, accesser);
        return;
    }
    switch (kind) {
    case 32: { ResetPolicy<32> policy = {}; fn_27_31A1D8(&policy); return; }
    case 33: { ResetPolicy<33> policy = {}; fn_27_31A3D0(&policy); return; }
    case 34: { ResetPolicy<34> policy = {}; fn_27_31A5BC(&policy); return; }
    case 35: { ResetPolicy<35> policy = {}; fn_27_31A79C(&policy); return; }
    case 36: return;
    case 37: return;
    case 38: return;
    case 39: return;
    default: return;
    }
}
