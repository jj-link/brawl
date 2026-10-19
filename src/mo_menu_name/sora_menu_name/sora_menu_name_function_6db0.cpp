#pragma force_active on
class gfPadSystem {
public:
    void readGameDataRequest(int, int, int, int);
};

extern gfPadSystem* g_gfPadSystem;

struct MenuName {
    unsigned char padding[0x40];
    unsigned int controller;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4C;
    unsigned char gameData[0x80];
    unsigned int fieldD0;
    unsigned int fieldD4;
};

extern "C" void fn_16_6DB0(MenuName* self) {
    self->field48 = 0;
    self->field44 = 0;
    g_gfPadSystem->readGameDataRequest(
        self->controller & 0xFF,
        reinterpret_cast<int>(self->gameData),
        0x40,
        0
    );
    self->fieldD0 = 1;
    self->fieldD4 = 1;
}
