#pragma force_active on
extern "C" float randf__Fv();

class grTenganEvent {
public:
    void set(float a, float b);

    int unk0;
    float unk4;
    float unk8;
    float unkC;
};

void grTenganEvent::set(float a, float b) {
    unk4 = a;
    unk8 = b;
    unkC = (unk8 - unk4) * randf__Fv() + unk4;
}
