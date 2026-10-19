#pragma force_active on
extern "C" void* fn_98_14750(void* owner);
extern "C" void* fn_98_14878(void* owner);
extern "C" void fn_98_1834C(void* weapon, void* attack);
extern "C" void fn_98_14074(void* owner, int flag);

extern "C" void fn_98_14074(void* owner, int flag) {
    void* weapon = fn_98_14750(owner);
    if (weapon) {
        void* p60 = *(void**)((char*)owner + 0x60);
        void* pd8 = *(void**)((char*)p60 + 0xd8);
        void* attack = *(void**)((char*)pd8 + 0x1c);
        fn_98_1834C(weapon, attack);
    }
    if (flag) {
        void* next = fn_98_14878(owner);
        if (next) {
            fn_98_14074(next, 1);
        }
    }
}
