#include <snd/snd_system.h>
#include <gm/gm_global.h>
#pragma force_active on
#pragma pack(push, 1)
struct Result { unsigned int words[11]; unsigned char last; };
#pragma pack(pop)
struct Data0 { char pad[0xfd]; unsigned char index; };
struct Data { Data0* first; char pad[0xb0]; unsigned int b4; char pad2[0xb0]; unsigned char input[1]; char pad3[0x57]; short timer; };
struct Self { char pad[0x40]; Data* data; };
extern "C" void fn_2_30A44(Result*, Self*, void*);
extern "C" void fn_8004DA60(void*, unsigned char, const void*);
extern "C" void fn_2_31A5C(Self*, unsigned int, int);
extern "C" void fn_2_31EB8(Self*, int, int);
extern "C" void fn_2_35880(Self* self) {
    GameGlobal* global = g_GameGlobal;
    unsigned char index = self->data->first->index;
    Result temp;
    Result result;
    fn_2_30A44(&temp, self, self->data->input);
    result = temp;
    fn_8004DA60(global, index, &result);
    fn_2_31A5C(self, self->data->b4, -1);
    fn_2_31EB8(self, 2, 0x21);
    g_sndSystem->playSE((SndID)0x27, -1, 0, 0, -1);
    self->data->timer = 0x78;
}