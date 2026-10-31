#pragma force_active on
class grGimmickWindData2nd;

class stTrigger {
public:
    void setWindParam(grGimmickWindData2nd* data, long value);
};

class stMelee {
public:
    void updateWind2ndOnly();

private:
    char pad_0000[0x1c4];
    stTrigger* m_trigger;
    grGimmickWindData2nd* m_windData;
};

void stMelee::updateWind2ndOnly() {
    stTrigger* trigger = m_trigger;
    if (trigger == 0) {
        return;
    }
    grGimmickWindData2nd* data = m_windData;
    if (data == 0) {
        return;
    }
    trigger->setWindParam(data, 0);
}
