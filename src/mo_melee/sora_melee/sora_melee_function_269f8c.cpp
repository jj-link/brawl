#pragma force_active on

struct SimpleEffectData {
    unsigned char data[16];
};

class EffectBase {
    unsigned char padding[0x3c];

public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void unused71();
    virtual void unused72();
    virtual void unused73();
    virtual void unused74();
    virtual void unused75();
    virtual void unused76();
    virtual void unused77();
    virtual void unused78();
    virtual void unused79();
    virtual void unused80();
    virtual void unused81();
    virtual void unused82();
    virtual void unused83();
    virtual void unused84();
    virtual void setEffect(SimpleEffectData*, const char*, void*);
};

class grGimmick : public EffectBase {
public:
    unsigned char padding2[0xbc];
    unsigned char effect;
};

extern "C" {
extern const char lbl_27_data_56504[];
extern const char lbl_27_data_56500[];

void createSimpleEffectData__9grGimmickFPQ29grGimmick16SimpleEffectDataiPCc(
    grGimmick*, SimpleEffectData*, int, const char*);

void fn_27_269F8C(grGimmick* self) {
    SimpleEffectData data;
    createSimpleEffectData__9grGimmickFPQ29grGimmick16SimpleEffectDataiPCc(
        self, &data, 0x01030023, lbl_27_data_56504);
    self->setEffect(&data, lbl_27_data_56500, &self->effect);
}
}
