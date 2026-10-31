#pragma force_active on
extern "C" void fn_95_1032C(void* fighter);

extern "C" void fn_95_12CC8(void*, void* fighter, int kind) {
    if (kind == 0x113 || (unsigned int)(kind - 0x119) <= 3) {
        fn_95_1032C(fighter);
    }
}
