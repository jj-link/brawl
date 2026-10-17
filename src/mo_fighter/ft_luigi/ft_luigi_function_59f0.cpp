extern "C" {
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_99_5AA4(void*, short);
void* fn_99_5B10(void*, short);
void* fn_99_5B6C(void*, short);
void* fn_99_5BC8(void*, short);
void* fn_99_5C24(void*, short);
void* fn_99_5C80(void*, short);
}

// Tear down the member and base layers of Luigi's embedded special-state config.
// A positive deleting flag releases this config's storage, not the outer fighter.
extern "C" void* fn_99_59F0(void* gp, short deleting) {
    if (gp) {
        unsigned char* storage = static_cast<unsigned char*>(gp);
        int destroyMember = -1;
        fn_27_13C90(storage + 0x224, destroyMember);
        fn_99_5AA4(storage + 0x1E8, destroyMember);
        fn_27_21038(storage + 0x1D8, destroyMember);
        fn_99_5B10(storage + 0x1B8, destroyMember);
        fn_99_5B6C(storage + 0x198, destroyMember);
        fn_99_5BC8(storage + 0x160, destroyMember);
        fn_99_5C24(storage + 0xC4, destroyMember);
        fn_99_5C80(gp, destroyMember);
        if (deleting > 0) operator delete(gp);
    }
    return gp;
}
