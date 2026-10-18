#pragma force_active on
extern "C" void fn_40_2AA70(void* self, unsigned int valid);

extern "C" void fn_40_2AA70(void* self, unsigned int valid) {
    extern void setValid__10grYakumonoFUl(void*, unsigned int);
    extern void setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(
        void*, int, int, unsigned int, void*, void*);

    setValid__10grYakumonoFUl(self, valid);

    if (valid == 1) {
        unsigned char* data = *reinterpret_cast<unsigned char**>(
            reinterpret_cast<unsigned char*>(self) + 0x154);
        setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(
            self, 0, 0, 0, data + 0x1E4, 0);
    }
}
