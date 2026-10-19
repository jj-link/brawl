#pragma force_active on
extern "C" {
void setValid__10grYakumonoFUl(void* self, unsigned long valid);
void disableAttack__10grYakumonoFUl(void* self, unsigned long flag);
void setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(void* self, int a, int b, unsigned long c, void* data, void* details);
}

extern "C" void fn_40_27E98(void* self, unsigned long arg) {
    setValid__10grYakumonoFUl(self, arg);
    if (arg == 1) {
        disableAttack__10grYakumonoFUl(self, 0);
        char* p = *(char**)((char*)self + 0x158);
        setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(self, 0, 0, 0, p + 0x1ec, 0);
    }
}
