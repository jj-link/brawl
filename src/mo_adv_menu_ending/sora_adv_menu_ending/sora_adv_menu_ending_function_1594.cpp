#include <types.h>
#include <mu/mu_msg.h>
#include <mt/mt_vector.h>
#include <string.h>
#pragma force_active on
struct EndingEntry {
    u16 message; u8 spacing; u8 pad; int x; int y;
    u8 scale; u8 align; u8 color; u8 padF;
};
struct EndingHeader { int pad; float duration; u16 count; };
struct EndingScale { float x, y; };
struct EndingColor { u8 r, g, b, a; };
struct Ending {
    char pad0[0x60]; void* objects[2]; char pad68[8];
    void** lines; MuMsg* msg; char pad78[0x10];
    EndingHeader* header; char pad8C[0xC]; float* positions;
    EndingScale* scales; EndingColor* colors; EndingEntry* entries;
    int count; char padAC[0xC]; float speed; char padBC[4];
    float* linePositions;
};
extern "C" {
extern float lbl_37_rodata_0;
extern float lbl_37_rodata_40;
void fn_800B6838(void*, const Vec3f*);
void* getMsgData__5MuMsgFUlPPv(MuMsg*, unsigned long, void**);
void fn_800B92D8(MuMsg*, unsigned long, char*, unsigned long);
}
extern "C" void fn_37_1594(Ending* self) {
    float speed = self->header->duration / (float)self->header->count;
    self->speed = speed;
    int spacing = 0;
    int i;
    for (i = 0; i < self->count; ++i) {
        EndingEntry* entry = &self->entries[i];
        spacing += entry->spacing;
        float x = (float)entry->x;
        float y = (float)(entry->y - spacing);
        Vec3f pos;
        pos.m_x = x;
        pos.m_y = y;
        pos.m_z = 0.0f;
        fn_800B6838(self->lines[i], &pos);
        self->linePositions[i] = -1.0f * y;
        EndingScale* scale = &self->scales[self->entries[i].scale];
        float sy = scale->y;
        self->msg->setHScale(i, scale->x);
        self->msg->getHScale(i, sy);
        EndingColor* color = &self->colors[self->entries[i].color];
        self->msg->setFontColor(i, color->r, color->g, color->b, color->a);
        switch (self->entries[i].align) {
        case 0: self->msg->setAlignMode(i, MuMsg::Align_Center); break;
        case 1: self->msg->setAlignMode(i, MuMsg::Align_Left); break;
        case 2: self->msg->setAlignMode(i, MuMsg::Align_Right); break;
        }
        u16 message = self->entries[i].message;
        char buffer[256];
        void* size;
        memset(buffer, 0, 256);
        void* text = getMsgData__5MuMsgFUlPPv(self->msg, message, &size);
        memcpy(buffer, text, (unsigned long)size);
        fn_800B92D8(self->msg, i, buffer, strlen(buffer));
    }
    for (int j = 0; j < 2; ++j) {
        float y = -1.0f * self->positions[j];
        Vec3f pos;
        pos.m_x = 0.0f;
        pos.m_y = y;
        pos.m_z = 0.0f;
        fn_800B6838(self->objects[j], &pos);
    }
}
