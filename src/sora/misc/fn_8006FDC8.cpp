#include <ms/ms_char_writer.h>
#include <nw4r/ut/ut_Font.h>
#pragma force_active on

extern "C" float GetFontDescent_Q22ms10CharWriterCFv(const ms::CharWriter* self) {
    const nw4r::ut::Font* font = static_cast<const nw4r::ut::Font*>(self->m_font);
    return self->m_104 * (self->m_fontScaleY * (float)font->GetDescent());
}
