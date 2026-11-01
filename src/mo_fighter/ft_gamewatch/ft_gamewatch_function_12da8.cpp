#pragma force_active on

struct Vec2f {
    float m_x;
    float m_y;
};

class Class_3868 {
public:
    virtual void fn_107_8720();
    virtual void fn_107_1AF8();
    virtual void fn_107_C434();
    virtual void fn_107_C42C();
    virtual void fn_107_C424();
    virtual void fn_107_C41C();
    virtual void* fn_107_C414(int);
};

class GameWatchEnergyView {
public:
    virtual void update();
    virtual void updateEnergy(void*);
    virtual Vec2f getSpeed();

    int m_unk;
    Vec2f m_speed;
};

extern "C" {
extern const char lbl_107_data_8E20[];
extern const char lbl_107_data_3B18[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
void* __memcpy(void*, const void*, unsigned long);
void fn_107_14560(void*, void*, int);
}

extern "C" void fn_107_12DA8(void* self, void* accesser, int kind) {
    switch (kind) {
    case 0x120:
    case 0x125:
    case 0x132:
    case 0x137:
        break;
    default: {
        void* enumeration = *(void**)((char*)accesser + 0xD8);
        Class_3868* kinetic =
            *(Class_3868**)((char*)enumeration + 0x7C);
        void* energy = kinetic->fn_107_C414(2);
        GameWatchEnergyView* view =
            (GameWatchEnergyView*)__dynamic_cast(
                energy, 0, lbl_107_data_8E20, lbl_107_data_3B18, 1);

        Vec2f adjusted;
        Vec2f speed = view->getSpeed();
        __memcpy(&adjusted, &speed, sizeof(Vec2f));
        float multiplier =
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                accesser, 0xC35, 0);
        adjusted.m_x *= multiplier;
        view->m_speed.m_x = adjusted.m_x;
        view->m_speed.m_y = adjusted.m_y;
        break;
    }
    }

    fn_107_14560(self, accesser, kind);
}
