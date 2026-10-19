#pragma force_active on
struct soDamage;
struct soDamageAttackerInfo;

class grYakumono {
public:
    void onDamage(int, soDamage*, soDamageAttackerInfo*);
};

extern "C" void fn_27_264DDC(void* self);

extern "C" void fn_40_39C14(grYakumono* self, int arg1, soDamage* damage, soDamageAttackerInfo* attacker) {
    fn_27_264DDC(self);
    self->onDamage(arg1, damage, attacker);
}
