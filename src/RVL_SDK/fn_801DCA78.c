#include <types.h>
#include <revolution/OS/OSFont.h>
#pragma force_active on
extern void fn_801DC7C0(void);
extern u16 lbl_8059E9E0;
extern const char* (*lbl_805A06B0)(int, const char*, void*, void*);
static inline u16 get(void)
{
    s32 value;
    if (lbl_8059E9E0 != 0xFFFF) return lbl_8059E9E0;
    switch (*(s32*)0x800000CC) {
    case 0:
        value = (*(u16*)0xCC00206E >> 1) & 1;
        lbl_8059E9E0 = value;
        break;
    case 1:
    case 2:
    default:
        value = 0;
        lbl_8059E9E0 = 0;
        break;
    }
    lbl_805A06B0 = (void*)fn_801DC7C0;
    return (u16)value;
}
const char* fn_801DCA78(const char* str, void* dst, s32 xOfs, s32 arg3, u32* widthOut)
{
    OSFontHeader* font;
    s32 numRestTex;
    u8* local_24;
    s32 row;
    u8* local_20;
    s32 col;
    s32 local_48;
    u32 code;
    int j;
    int i;
    u32 sheet;
    u8* local_4C;
    u8* font_u8;
    u8* tex;
    s32 local_44;

    str = lbl_805A06B0(get(), str, &font, &code);
    local_4C = &font->c0;
    sheet = (s32)code / (font->sheetNumCol * font->sheetNumRow);
    numRestTex = code - (sheet * (font->sheetNumCol * font->sheetNumRow));
    row = numRestTex / font->sheetNumCol;
    col = numRestTex - row * font->sheetNumCol;
    row *= font->cellHeight;
    col *= font->cellWidth;
    tex = (u8*)font + font->sheetImageOfs;
    tex += sheet * font->sheetSize / 2;

    for (i = 0; i < font->cellHeight; i++) {
        for (j = 0; j < font->cellWidth; j++) {
            local_20 = tex + (((font->sheetWidth / 8) * 32) / 2) * ((row + i) / 8);
            local_20 += ((col + j) / 8) * 16;
            local_20 += ((row + i) % 8) * 2;
            local_20 += ((col + j) % 8) / 4;
            local_44 = (col + j) % 4;
            local_24 = (u8*)dst + ((i / 8) * (((arg3 * 4) / 8) * 32));
            local_24 += (((xOfs + j) / 8) * 32);
            local_24 += ((i % 8) * 4);
            local_24 += ((xOfs + j) % 8) / 2;
            local_48 = (xOfs + j) % 2;
            *local_24 |= (u8)(local_4C[(*local_20 >> (6 - (local_44 * 2))) & 3] &
                               (local_48 != 0 ? 0x0F : 0xF0));
        }
    }
    if (widthOut != 0) {
        font_u8 = (u8*)font;
        *widthOut = (font_u8 + font->widthTableOfs)[code];
    }
    return str;
}