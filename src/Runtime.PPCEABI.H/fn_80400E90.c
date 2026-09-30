// Release the buffer associated with a TRK event.
typedef unsigned long u32;
struct TRKEvent {
    u32 type;
    u32 value;
    u32 buffer_id;
};
extern void fn_804018D8(u32);

void TRKDestructEvent(struct TRKEvent* event) {
    fn_804018D8(event->buffer_id);
}
