#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" void fn_27_11F274(void* slot, u8 arg1, u32 arg2, u32 arg3);

struct FtSlotManagerStub {
    u8* m_slots;
};

struct FtSlotArgStub {
    u8 pad0[0x8];
    u8 count;
    u8 pad1[0xF];
    s32 index;
};

extern FtSlotManagerStub* g_ftSlotManager;

extern "C" void fn_27_115830(FtSlotArgStub* arg) {
    for (u8 i = 0; i < arg->count; i++) {
        fn_27_11F274(g_ftSlotManager->m_slots + arg->index * 0x4d4, i, 0x2000, 0);
    }
}
