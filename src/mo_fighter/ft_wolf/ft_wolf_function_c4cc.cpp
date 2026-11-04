#pragma force_active on
extern "C" {
extern char lbl_125_data_7034[];
extern char lbl_125_data_6EC4[];
extern char lbl_125_data_6D54[];
extern char lbl_125_data_6BE8[];
extern char lbl_125_data_2838[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

namespace {
struct State {
    bool a;
    bool b;
};
}

class WnWeaponBuilder {
public:
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual void fn3();
    virtual void fn4();
    virtual void fn5();
    virtual unsigned int getType();
};

extern "C" int fn_125_C4CC(void*, void*, void* self) {
    WnWeaponBuilder* obj = reinterpret_cast<WnWeaponBuilder*>(self);
    switch (obj->getType()) {
        case 0: { State s = {false, false}; __dynamic_cast(self, 0, lbl_125_data_7034, lbl_125_data_2838, 1); return 1; }
        case 1: { State s = {false, false}; __dynamic_cast(self, 0, lbl_125_data_6EC4, lbl_125_data_2838, 1); return 1; }
        case 2: { State s = {false, false}; __dynamic_cast(self, 0, lbl_125_data_6D54, lbl_125_data_2838, 1); return 1; }
        case 3: { State s = {false, false}; __dynamic_cast(self, 0, lbl_125_data_6BE8, lbl_125_data_2838, 1); return 1; }
        case 4: { State s = {false, false}; return 1; }
        case 5: { State s = {false, false}; return 1; }
        case 6: { State s = {false, false}; return 1; }
        case 7: { State s = {false, false}; return 1; }
        case 8: { State s = {false, false}; return 1; }
        case 9: { State s = {false, false}; return 1; }
        case 10: { State s = {false, false}; return 1; }
        case 11: { State s = {false, false}; return 1; }
        case 12: { State s = {false, false}; return 1; }
        case 13: { State s = {false, false}; return 1; }
        case 14: { State s = {false, false}; return 1; }
        case 15: { State s = {false, false}; return 1; }
        case 16: { State s = {false, false}; return 1; }
        default: return 0;
    }
}
