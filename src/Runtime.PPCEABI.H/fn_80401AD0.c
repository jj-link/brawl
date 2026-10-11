typedef unsigned long u32;

struct TRKEvent {
    u32 type;
    u32 value;
    u32 buffer_id;
};

struct TRKMessageBuffer;

extern void fn_80400EB4(struct TRKEvent* event, u32 type);
extern int fn_80400ECC(struct TRKEvent* event);
extern int fn_80401B80(void);
extern struct TRKMessageBuffer* TRKGetBuffer(int buffer_id);
extern int lbl_8059B928[6];

static inline void TRKPostInputEvent(int buffer_id) {
    struct TRKEvent event;

    fn_80400EB4(&event, 2);
    event.buffer_id = buffer_id;
    lbl_8059B928[0] = -1;
    fn_80400ECC(&event);
}

void fn_80401AD0(int buffer_id) {
    TRKPostInputEvent(buffer_id);
}

void TRKGetInput(void) {
    int buffer_id = fn_80401B80();

    if (buffer_id != -1) {
        TRKGetBuffer(buffer_id);
        TRKPostInputEvent(buffer_id);
    }
}
