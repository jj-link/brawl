#pragma force_active on
namespace StSeUtil {
class SeSeq {
public:
    void playFrame(long, float, float);
    void playFrame(long, float);
};
}

struct IceBase {
    unsigned char unused00[0x3C];
};

struct Ice : IceBase {
    virtual void unusedVirtual0();
    virtual void unusedVirtual1();
    virtual void unusedVirtual2();
    virtual void unusedVirtual3();
    virtual void unusedVirtual4();
    virtual void unusedVirtual5();
    virtual void unusedVirtual6();
    virtual void unusedVirtual7();
    virtual void unusedVirtual8();
    virtual void unusedVirtual9();
    virtual void unusedVirtual10();
    virtual void unusedVirtual11();
    virtual void unusedVirtual12();
    virtual void unusedVirtual13();
    virtual void unusedVirtual14();
    virtual void unusedVirtual15();
    virtual void unusedVirtual16();
    virtual void unusedVirtual17();
    virtual void unusedVirtual18();
    virtual void unusedVirtual19();
    virtual void unusedVirtual20();
    virtual void unusedVirtual21();
    virtual void unusedVirtual22();
    virtual void unusedVirtual23();
    virtual void unusedVirtual24();
    virtual void unusedVirtual25();
    virtual void unusedVirtual26();
    virtual void setEnabled(int);
    virtual void unusedVirtual27();
    virtual void unusedVirtual28();
    virtual void unusedVirtual29();
    virtual void unusedVirtual30();
    virtual void unusedVirtual31();
    virtual void unusedVirtual32();
    virtual void unusedVirtual33();
    virtual void unusedVirtual34();
    virtual void unusedVirtual35();
    virtual void unusedVirtual36();
    virtual void unusedVirtual37();
    virtual void unusedVirtual38();
    virtual void unusedVirtual39();
    virtual void unusedVirtual40();
    virtual void unusedVirtual41();
    virtual void unusedVirtual42();
    virtual void unusedVirtual43();
    virtual void unusedVirtual44();
    virtual void unusedVirtual45();
    virtual void unusedVirtual46();
    virtual void unusedVirtual47();
    virtual void unusedVirtual48();
    virtual void unusedVirtual49();
    virtual void unusedVirtual50();
    virtual void unusedVirtual51();
    virtual void unusedVirtual52();
    virtual void unusedVirtual53();
    virtual void unusedVirtual54();
    virtual void unusedVirtual55();
    virtual void unusedVirtual56();
    virtual void unusedVirtual57();
    virtual void unusedVirtual58();
    virtual void unusedVirtual59();
    virtual void unusedVirtual60();
    virtual void unusedVirtual61();
    virtual void unusedVirtual62();
    virtual void unusedVirtual63();
    virtual void unusedVirtual64();
    virtual void unusedVirtual65();
    virtual float getFrame(int);

    unsigned char unused40[0x110];
    unsigned char state;
    unsigned char unused151[7];
    unsigned char* event;
    StSeUtil::SeSeq sequence;
};

extern "C" const float lbl_62_rodata_68[];

extern "C" void fn_62_2FB8(Ice* self) {
    switch (self->state) {
    case 0:
        self->setEnabled(0);
        self->state = 1;
    case 1:
        if (*self->event == 5) {
            self->setEnabled(1);
            self->sequence.playFrame(0, self->getFrame(0), lbl_62_rodata_68[0]);
            self->state = 7;
        }
        break;
    case 7:
        self->sequence.playFrame(0, self->getFrame(0));
        if (*self->event != 5) {
            self->state = 0;
        }
        break;
    }
}
