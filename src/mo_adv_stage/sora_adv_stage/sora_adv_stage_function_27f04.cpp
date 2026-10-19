#pragma force_active on
struct grYakumono;

extern "C" void setValidAttachedEffect__10grYakumonoFUl(grYakumono*, unsigned int);
extern "C" void disableAttack__10grYakumonoFUl(grYakumono*, unsigned int);
extern "C" void setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(
    grYakumono*, int, int, unsigned int, void*, void*);

extern "C" void fn_40_27F04(grYakumono* self, unsigned int effect) {
    setValidAttachedEffect__10grYakumonoFUl(self, effect);
    if (effect == 1) {
        disableAttack__10grYakumonoFUl(self, 0);
        unsigned char* data = *reinterpret_cast<unsigned char**>(
            reinterpret_cast<unsigned char*>(self) + 0x158);
        setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(
            self, 0, 0, 0, data + 0x1EC, 0);
    }
}
