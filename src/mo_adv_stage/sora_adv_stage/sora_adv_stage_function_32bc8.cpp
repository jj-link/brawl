#pragma force_active on
struct Base {
    char pad0[0x3c];
};

struct Object : Base {
    virtual void virtual0();
    virtual void virtual1();
    virtual void virtual2();
    virtual void virtual3();
    virtual void virtual4();
    virtual void virtual5();
    virtual void virtual6();
    virtual void virtual7();
    virtual void virtual8();
    virtual void virtual9();
    virtual void virtual10();
    virtual void virtual11();
    virtual void virtual12();
    virtual void virtual13();
    virtual void virtual14();
    virtual void virtual15();
    virtual void virtual16();
    virtual void virtual17();
    virtual void virtual18();
    virtual void virtual19();
    virtual void virtual20();
    virtual void virtual21();
    virtual void virtual22();
    virtual void virtual23();
    virtual void virtual24();
    virtual void virtual25();
    virtual void virtual26();
    virtual void virtual27();
    virtual void virtual28();
    virtual void virtual29();
    virtual void virtual30();
    virtual void virtual31();
    virtual void virtual32();
    virtual void virtual33();
    virtual void virtual34();
    virtual void virtual35();
    virtual void virtual36();
    virtual void virtual37();
    virtual void virtual38();
    virtual void virtual39();
    virtual void virtual40();
    virtual void virtual41();
    virtual void virtual42();
    virtual void virtual43();
    virtual void virtual44();
    virtual void virtual45();
    virtual void virtual46();
    virtual void virtual47();
    virtual void virtual48();
    virtual void virtual49();
    virtual void virtual50();
    virtual void virtual51();
    virtual void virtual52();
    virtual void virtual53();
    virtual void virtual54();
    virtual void virtual55();
    virtual void virtual56();
    virtual void virtual57();
    virtual void virtual58();
    virtual void virtual59();
    virtual void virtual60();
    virtual void virtual61();
    virtual void virtual62();
    virtual void virtual63();
    virtual void virtual64();
    virtual void virtual65();
    virtual void virtual66();
    virtual void virtual67();
    virtual void virtual68();
    virtual void virtual69();
    virtual void virtual70();
    virtual void virtual71();
    virtual void virtual72();
    virtual void virtual73();
    virtual void virtual74();
    virtual void virtual75();
    virtual void finish(int);

    char pad40[0x124];
    int state;
};

typedef void (Object::*StateFunction)(float);

struct StateTable {
    StateFunction entries[6];
};

extern "C" {
extern const StateTable lbl_40_rodata_638;
void update__9grGimmickFf(Object*, float);

void fn_40_32BC8(Object* self, float deltaFrame) {
    StateTable table = lbl_40_rodata_638;
    (self->*table.entries[self->state])(deltaFrame);
    update__9grGimmickFf(self, deltaFrame);
    self->finish(0);
}
}
