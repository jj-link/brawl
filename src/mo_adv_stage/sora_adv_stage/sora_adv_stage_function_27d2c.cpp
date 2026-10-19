#pragma force_active on
extern "C" void setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(
    void*, int, int, unsigned int, void*, void*);

extern "C" void fn_40_27D2C(void* self) {
    unsigned char* data = *reinterpret_cast<unsigned char**>(
        reinterpret_cast<unsigned char*>(self) + 0x158);
    unsigned int value = *reinterpret_cast<unsigned int*>(data + 0x23C);
    setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(
        self, 0, 0, value, data + 0x1EC, 0);
}
