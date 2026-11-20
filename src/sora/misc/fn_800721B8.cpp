#include <ms/ms_char_writer.h>
#pragma force_active on

extern "C" {
extern const float lbl_805A1AA0;
extern const float lbl_805A1AB8;
void __dt__Q22ms10CharWriterFv(void*, int);
float fn_800714AC(void*, int, int);
void fn_80071C38(void*, float*, int, int);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(void*, int);
    virtual void slot4(void*);
};

struct WriterData {
    GXColor color0, color1, color2, color3, color4, color5, color6;
    struct ColorComponents {
        unsigned char red, green;
    } color7RG;
    unsigned char b7, a7;
    unsigned int w20;
    union WordPair {
        unsigned int words[2];
        unsigned char bytes[8];
    } w24_28, w2c_30;
    unsigned int w34;
    WordPair w38_3c;
    unsigned char b40, b41, b42, b43;
    float value44;
    unsigned int word48;
    unsigned char byte4c, pad4d[3];
    float value50;
    unsigned char b54, b55, pad56[2];
    float value58, value5c;
    unsigned char b60, b61, b62, b63;
    unsigned int word64;
    float value68;
    unsigned char byte6c, pad6d[3];
    unsigned int word70;
    float value74, value78, value7c, value80;
    float value84, value88, value8c;
    unsigned int word90, mode94;
    Object_vptr_0* object98;
    unsigned int word9c;

    WriterData(const WriterData& other)
        : color0(other.color0),
          color1(other.color1),
          color2(other.color2),
          color3(other.color3),
          color4(other.color4),
          color5(other.color5),
          color6(other.color6),
          color7RG(other.color7RG),
          b7(other.b7),
          a7(other.a7),
          w20(other.w20),
          w24_28(other.w24_28),
          w2c_30(other.w2c_30),
          w34(other.w34),
          w38_3c(other.w38_3c),
          b40(other.b40),
          b41(other.b41),
          b42(other.b42),
          b43(other.b43),
          value44(other.value44),
          word48(other.word48),
          byte4c(other.byte4c),
          value50(other.value50),
          b54(other.b54),
          b55(other.b55),
          value58(other.value58),
          value5c(other.value5c),
          b60(other.b60),
          b61(other.b61),
          b62(other.b62),
          b63(other.b63),
          word64(other.word64),
          value68(other.value68),
          byte6c(other.byte6c),
          word70(other.word70),
          value74(other.value74),
          value78(other.value78),
          value7c(other.value7c),
          value80(other.value80),
          value84(other.value84),
          value88(other.value88),
          value8c(other.value8c),
          word90(other.word90),
          mode94(other.mode94),
          object98(other.object98),
          word9c(other.word9c)
    {}
};

struct LocalArgs {
    WriterData* writer;
    int arg;
    int zero[4];
};

extern "C" float fn_800721B8(
    WriterData* arg0, float* arg1, float* arg2,
    int arg3, int arg4, float* arg5, float* arg6
) {
    float result = lbl_805A1AA0;
    float result2 = result;
    unsigned int mode = arg0->mode94 & 0x333;

    if (mode != 0x300 && mode != 0) {
        float bounds[4];
        bounds[0] = result;
        bounds[1] = result;
        bounds[2] = result;
        bounds[3] = result;

        WriterData local(*arg0);
        int zero = 0;

        LocalArgs args;
        args.zero[0] = zero;
        args.zero[1] = zero;
        args.zero[2] = zero;
        args.zero[3] = zero;
        args.writer = &local;
        args.arg = arg3;

        arg0->object98->slot3(&args, local.word9c);
        fn_80071C38(&local, bounds, arg3, arg4);
        arg0->object98->slot4(&args);
        __dt__Q22ms10CharWriterFv(&local, 0);

        result = bounds[0] + bounds[2];
        result2 = bounds[1] + bounds[3];
    }

    unsigned int align = arg0->mode94 & 0x30;
    if (align == 0x10)
        *arg1 -= result * lbl_805A1AB8;
    else if (align == 0x20)
        *arg1 -= result;

    unsigned int just = arg0->mode94 & 3;
    if (just == 1) {
        float width = fn_800714AC(arg0, arg3, arg4);
        float delta = result - width;
        float half = delta * lbl_805A1AB8;
        float scaled = half * arg0->value84;
        ((ms::CharWriter*)arg0)->SetCursorX(*arg1 + scaled);
    } else if (just == 2) {
        float width = fn_800714AC(arg0, arg3, arg4);
        float delta = result - width;
        float scaled = delta * arg0->value84;
        ((ms::CharWriter*)arg0)->SetCursorX(*arg1 + scaled);
    } else {
        ((ms::CharWriter*)arg0)->SetCursorX(*arg1);
    }

    if ((arg0->mode94 & 0x300) == 0x300) {
        ((ms::CharWriter*)arg0)->SetCursorY(*arg2);
    } else {
        ((ms::CharWriter*)arg0)->SetCursorY(
            *arg2 + ((ms::CharWriter*)arg0)->GetFontAscent()
        );
    }

    *arg5 = result;
    *arg6 = result2;
    return result;
}
