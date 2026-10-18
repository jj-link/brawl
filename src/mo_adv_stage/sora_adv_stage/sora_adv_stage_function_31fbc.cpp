#pragma force_active on
class grYakumono {
public:
    void disableAttack(unsigned long);
};

extern "C" void fn_40_31FBC(grYakumono* self) {
    self->disableAttack(0);
}
