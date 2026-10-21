#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Width {
    u8 left, glyph, advance;
};

struct WidthBlock {
    u16 first, last;
    WidthBlock* next;
    Width widths[1];
};

struct Sheet {
    u8 cellWidth, cellHeight;
    u16 unknown2;
    u32 sheetSize;
    u16 unknown8, format;
    u16 columns, rows;
    u16 width, height;
    u8* image;
};

struct Font {
    u32 unknown0;
    Width defaultWidth;
    u8 unknown7;
    Sheet* sheet;
    WidthBlock* widths;
};

struct Object {
    u8 unknown0[0x14];
    Font* font;
};

struct Glyph {
    u8* image;
    Width widths;
    u8 height;
    u32 format;
    u16 width, sheetHeight;
    u16 x, y;
};

static inline const Width* getWidth(WidthBlock* block, u32 index, Font* font) {
    while (block) {
        if (block->first <= index && index <= block->last)
            return &block->widths[index - block->first];
        block = block->next;
    }
    return &font->defaultWidth;
}

extern "C" void fn_8015E4E4(Object* self, Glyph* out, u32 index) {
    Sheet* sheet = self->font->sheet;
    u32 count = sheet->columns * sheet->rows;
    u32 page = index / count;
    u32 rem = index % count;
    u32 row = rem / sheet->columns;
    u32 col = rem % sheet->columns;
    u32 x = col * (sheet->cellWidth + 1);
    u32 y = row * (sheet->cellHeight + 1);

    out->image = sheet->image + page * sheet->sheetSize;

    Font* font = self->font;
    const Width* widths = getWidth(font->widths, index, font);

    out->widths = *widths;
    out->height = sheet->cellHeight;
    out->format = sheet->format;
    out->width = sheet->width;
    out->sheetHeight = sheet->height;
    out->x = x + 1;
    out->y = y + 1;
}
