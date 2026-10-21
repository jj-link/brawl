#pragma force_active on
typedef unsigned char u8;

struct Color {
    u8 r, g, b, a;
};

struct Writer;

struct State {
    int unused;
    u8 disabled;
    u8 padding[3];
    int count;
};

struct FrameView {
    u8 padding[12];
    Color color;
    float scaleX;
    float scaleY;
    u8 flags;
};

extern "C" void SetTextColor__Q22ms10CharWriterFQ34nw4r2ut5Color(Writer*, Color);
extern "C" void SetScale__Q22ms10CharWriterFff(Writer*, float, float);
extern "C" int fn_8006FE30(Writer*);
extern "C" void SetFixedWidth__Q22ms10CharWriterFf(Writer*, float);

extern float lbl_805A1A38;

extern "C" int fn_8006D2E8(State* self, Writer** writerPtr) {
    int count = self->count;
    if (count < 1)
        return 0;

    self->count = --count;
    if (self->disabled)
        return 1;

    FrameView* frame = (FrameView*)((char*)self + count * 16);
    Writer* writer = *writerPtr;
    u8 flags = frame->flags;

    if (flags & 2) {
        SetTextColor__Q22ms10CharWriterFQ34nw4r2ut5Color(writer, frame->color);
    }

    if (flags & 1) {
        SetScale__Q22ms10CharWriterFff(writer, frame->scaleX, frame->scaleY);
        if (fn_8006FE30(*writerPtr)) {
            SetFixedWidth__Q22ms10CharWriterFf(
                *writerPtr, lbl_805A1A38 * frame->scaleX);
        }
    }

    return 1;
}
