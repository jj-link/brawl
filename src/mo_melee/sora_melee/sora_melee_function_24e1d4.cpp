#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
struct GameData { u8 pad[0x20]; u32 value; };
struct GameGlobal { u8 pad[8]; GameData* data; };
struct Object { u8 pad0[0x40]; u8 state; u8 pad1[0x8B]; float value; };
extern "C" {
extern GameGlobal* g_GameGlobal;
}
extern "C" void fn_27_24E1D4(Object* self) {
    self->state = 1;
    u32 value = g_GameGlobal->data->value;
    if (value != 0) {
        self->value = (float)value;
    } else {
        self->state = 3;
    }
}
