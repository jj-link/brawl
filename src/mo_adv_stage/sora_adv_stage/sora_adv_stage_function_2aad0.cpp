#pragma force_active on
struct grYakumono;

extern "C" void setValidAttachedEffect__10grYakumonoFUl(grYakumono*, unsigned int);
extern "C" void setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(
    grYakumono*, int, int, unsigned int, void*, void*);

extern "C" void fn_40_2AAD0(grYakumono* self, unsigned int effect) {
    setValidAttachedEffect__10grYakumonoFUl(self, effect);
    if (effect == 1) {
        unsigned int* base = *reinterpret_cast<unsigned int**>(
            reinterpret_cast<char*>(self) + 0x154);
        setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(
            self, 0, 0, 0, base + 0x79, 0);
    }
}
