#pragma force_active on

namespace {
struct PeachEventState {
    bool first;
    bool second;
};

class EventObj {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual unsigned int kind();
};
}

extern "C" {
extern const char lbl_103_data_6070[], lbl_103_data_1B94[], lbl_103_data_5F04[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" int fn_103_B098(void*, void*, EventObj* event)
{
    switch (event->kind()) {
    case 0: {
        PeachEventState state = {false, false};
        __dynamic_cast(event, 0, lbl_103_data_6070, lbl_103_data_1B94, 1);
        return 1;
    }
    case 1: {
        PeachEventState state = {false, false};
        __dynamic_cast(event, 0, lbl_103_data_5F04, lbl_103_data_1B94, 1);
        return 1;
    }
    case 2: { PeachEventState state = {false, false}; return 1; }
    case 3: { PeachEventState state = {false, false}; return 1; }
    case 4: { PeachEventState state = {false, false}; return 1; }
    case 5: { PeachEventState state = {false, false}; return 1; }
    case 6: { PeachEventState state = {false, false}; return 1; }
    case 7: { PeachEventState state = {false, false}; return 1; }
    case 8: { PeachEventState state = {false, false}; return 1; }
    case 9: { PeachEventState state = {false, false}; return 1; }
    case 10: { PeachEventState state = {false, false}; return 1; }
    case 11: { PeachEventState state = {false, false}; return 1; }
    case 12: { PeachEventState state = {false, false}; return 1; }
    case 13: { PeachEventState state = {false, false}; return 1; }
    case 14: { PeachEventState state = {false, false}; return 1; }
    case 15: { PeachEventState state = {false, false}; return 1; }
    case 16: { PeachEventState state = {false, false}; return 1; }
    default: return 0;
    }
}
