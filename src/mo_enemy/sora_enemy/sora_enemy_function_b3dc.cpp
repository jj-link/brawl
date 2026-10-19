#pragma force_active on
extern "C" unsigned int fn_41_B34C(void* p);
extern "C" void* getInstance__9emManagerFv();
extern "C" void* fn_41_D044(void* mgr, unsigned int id);
extern "C" void* fn_41_CECC(void* mgr, void* task);

extern "C" int fn_41_B3DC(void* p) {
    if (fn_41_B34C(p) == 1) {
        return -1;
    }
    void* task = fn_41_D044(getInstance__9emManagerFv(), *(unsigned int*)((char*)p + 0xB0));
    void* node = fn_41_CECC(getInstance__9emManagerFv(), task);
    return *(int*)((char*)node + 0x28);
}
