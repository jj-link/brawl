#include <ms/ms_char_writer.h>
#include <nw4r/ut/ut_Font.h>
#pragma force_active on

float ms::CharWriter::GetFontHeight() const {
    nw4r::ut::Font* font = (nw4r::ut::Font*)m_font;
    return m_104 * (m_fontScaleY * (float)font->GetHeight());
}
