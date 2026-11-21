#pragma force_active on
extern "C" void fn_100_109D4(void* fighter, unsigned int taskId);

extern "C" void fn_100_F3B0(int* event, void* fighter, void* object) {
    void* saved = fighter;
    if (event[0] == 0x3D) {
        fighter = *(void**)((char*)object + 0x28);
        fn_100_109D4(saved, (unsigned int)fighter);
    }
}