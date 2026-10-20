#pragma force_active on
#pragma opt_propagation off
#pragma scheduling off

extern "C" void setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(
    void* self, int a, int b, unsigned long c, void* data, void* details);

extern "C" void fn_40_2AA54(void* self)
{
    char* data = *reinterpret_cast<char**>(static_cast<char*>(self) + 0x154);

    setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(
        self, 0, 0, 0, data + 0x1E4, 0);
}
