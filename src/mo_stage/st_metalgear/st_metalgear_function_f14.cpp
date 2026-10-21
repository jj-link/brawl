#pragma force_active on
extern "C" float randf__Fv();

struct Parameters {
    char pad[0x38];
    float probability;
};

struct StageBase {
    char pad[0x3c];
};

#define SLOT(n) virtual void slot##n();
#define TEN(n) \
    SLOT(n##0) SLOT(n##1) SLOT(n##2) SLOT(n##3) SLOT(n##4) \
    SLOT(n##5) SLOT(n##6) SLOT(n##7) SLOT(n##8) SLOT(n##9)

struct Stage : StageBase {
    TEN(0) TEN(1) TEN(2) TEN(3) TEN(4) TEN(5) TEN(6)
    TEN(7) TEN(8) TEN(9) TEN(10) TEN(11) TEN(12) TEN(13)
    virtual void call(int);
    char pad1[0x5c];
    Parameters* parameters;
};

#undef TEN
#undef SLOT

struct GameMode {
    char pad[0x1c];
    unsigned char mode;
};

struct GameGlobal {
    char pad[8];
    GameMode* mode;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" void fn_71_F14(Stage* self) {
    GameMode* mode;
    Parameters* parameters = self->parameters;
    if (parameters == 0) return;
    mode = g_GameGlobal->mode;
    if (mode == 0) return;
    if (randf__Fv() > parameters->probability) return;

    int id;
    switch (mode->mode) {
    case 0: id = 13; break;
    case 1: id = 14; break;
    case 2: id = 15; break;
    default: return;
    }
    self->call(id);
}
