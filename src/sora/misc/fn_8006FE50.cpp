#include <ms/ms_char_writer.h>
#include <nw4r/ut/ut_Font.h>
#pragma force_active on

extern float lbl_805A1A88;

extern "C" void PrintGlyph__Q22ms10CharWriterFfffCPv(
    ms::CharWriter*, float, float, float, const void*);

extern "C" float Print__Q22ms10CharWriterFUs(
    ms::CharWriter* self, unsigned short ch) {
    nw4r::ut::Glyph glyph;
    static_cast<nw4r::ut::Font*>(self->m_font)->GetGlyph(&glyph, ch);

    float width;
    float offset;

    if (self->m_isFixedWidth) {
        width = self->m_fixedWidth;
        offset = width - self->m_unknownFontWidthModifier *
                         (self->m_fontScaleX *
                          (glyph.widths.charWidth * self->m_104));
        offset = offset * lbl_805A1A88 +
            self->m_unknownFontWidthModifier *
                (self->m_fontScaleX * (glyph.widths.left * self->m_104));
    } else {
        width = self->m_unknownFontWidthModifier *
                (self->m_fontScaleX * (glyph.widths.charWidth * self->m_104));
        offset = self->m_unknownFontWidthModifier *
                 (self->m_fontScaleX * (glyph.widths.left * self->m_104));
    }

    PrintGlyph__Q22ms10CharWriterFfffCPv(
        self, self->m_xPos + offset, self->m_yPos, self->m_zPos, &glyph);
    self->m_xPos += width;
    return width;
}