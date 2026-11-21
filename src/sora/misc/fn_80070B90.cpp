#include <types.h>
#include <ms/ms_char_writer.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual int slot11();
};

extern "C" f32 getAdjustFontScale__Q22ms10CharWrifterCFv(void*);

extern "C" void fn_80070B90(ms::CharWriter* self, f32 value) {
    Object_vptr_0* font = (Object_vptr_0*)self->GetFont();
    int height = font ? (int)(font->slot11() * getAdjustFontScale__Q22ms10CharWrifterCFv(self)) : 0;
    *(f32*)((char*)self + 0x8C) = value - (f32)height * self->GetScaleV();
}
