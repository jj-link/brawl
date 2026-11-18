#include <types.h>
#include <ms/ms_char_writer.h>
#include <nw4r/ut/ut_Font.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

using nw4r::ut::Min;
using nw4r::ut::Max;

struct Reader {
    const char* pos;
    u16 (Reader::*fn)();
};

struct Ctx {
    ms::CharWriter* self;
    const char* pos;
    int a, b, c, d;
};

class Printer {
public:
    virtual void s0();
    virtual void s1();
    virtual int s2(f32* box, u16 ch, Ctx* ctx);
    virtual void s3();
    virtual void s4(Ctx* ctx);
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
};

extern "C" {
extern const f32 lbl_805A1AA0;
void fn_80071C00(Reader* r, void* font);
f32 getAdjustFontScale__Q22ms10CharWrifterCFv(void* self);
int fn_8006FE30(void* self);
f32 GetFixedWidth__Q22ms10CharWriterCfv(void* self);
}

extern "C" int fn_800717D4(ms::CharWriter* self, f32* out, const char* start, int maxLen) {
    int flag;
    f32 cx;
    Reader reader;
    Ctx ctx;
    int h;

    h = 0;
    ctx.a = 0;
    ctx.b = 0;
    ctx.c = 0;
    ctx.d = 0;
    ctx.self = self;
    ctx.pos = start;
    void* fp = self->GetFont();
    cx = lbl_805A1AA0;
    flag = 0;
    fn_80071C00(&reader, fp);
    out[0] = lbl_805A1AA0;
    out[2] = lbl_805A1AA0;

    nw4r::ut::Font* font;
    nw4r::ut::Font* font2;
    f32 t;
    (font = (nw4r::ut::Font*)self->GetFont(),
     font != 0 ? (h = (int)(font->GetLineFeed() * getAdjustFontScale__Q22ms10CharWrifterCFv(self))) : h,
     t = *(f32*)((char*)self + 0x8C) + (f32)h * self->GetScaleV(),
     out[1] = Min(lbl_805A1AA0, t),
     font2 = (nw4r::ut::Font*)self->GetFont(),
     h = font2 != 0 ? (int)(font2->GetLineFeed() * getAdjustFontScale__Q22ms10CharWrifterCFv(self)) : 0);
    f32 t2 = *(f32*)((char*)self + 0x8C) + (f32)h * self->GetScaleV();
    out[3] = Max(lbl_805A1AA0, t2);

    reader.pos = start;
    u16 ch = (reader.*reader.fn)();

    while (reader.pos - start <= maxLen) {
        if ((int)ch < 0x20) {
            f32 box[4];
            box[0] = cx;
            box[1] = lbl_805A1AA0;
            box[2] = lbl_805A1AA0;
            box[3] = lbl_805A1AA0;
            ctx.pos = reader.pos;
            ctx.d = (flag == 0);
            self->SetCursorX(cx);
            int r = (*(Printer**)((char*)self + 0x98))->s2(box, ch, &ctx);
            reader.pos = ctx.pos;

            out[0] = Min(out[0], box[0]);
            out[1] = Min(out[1], box[1]);
            out[2] = Max(out[2], box[2]);
            out[3] = Max(out[3], box[3]);

            cx = self->GetCursorX();
            if (r == 4) {
                (*(Printer**)((char*)self + 0x98))->s4(&ctx);
                return maxLen;
            } else if (r == 1) {
                flag = 0;
            } else if (r == 2) {
                flag = 1;
            } else if (r == 3) {
                break;
            }
        } else {
            if (flag != 0) {
                cx += *(f32*)((char*)self + 0x88);
            }
            flag = 1;
            if (fn_8006FE30(self) != 0) {
                cx += GetFixedWidth__Q22ms10CharWriterCfv(self);
            } else {
                cx += self->GetScaleH() *
                    (((nw4r::ut::Font*)self->GetFont())->GetCharWidth(ch) *
                     getAdjustFontScale__Q22ms10CharWrifterCFv(self));
            }
            out[0] = Min(out[0], cx);
            out[2] = Max(out[2], cx);
        }
        ch = (reader.*reader.fn)();
    }
    return reader.pos - start;
}
