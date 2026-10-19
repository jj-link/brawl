#pragma force_active on
extern "C" void fn_40_31F18(void* self) {
    extern void setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(
        void*, int, int, unsigned int, void*, void*);
    unsigned char* data = *reinterpret_cast<unsigned char**>(
        reinterpret_cast<unsigned char*>(self) + 0x158);
    setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(
        self, 0, 0, 0, data + 0x1EC, 0);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(self) + 0x168) = 2;
}
