typedef unsigned long u32;

struct TRKEvent {
    u32 type;
    u32 value;
    u32 buffer_id;
};

struct TRKMessageBuffer;

extern int TRKGetNextEvent(struct TRKEvent* event);
extern struct TRKMessageBuffer* TRKGetBuffer(int buffer_id);
extern int TRKDispatchMessage(struct TRKMessageBuffer* buffer);
extern int TRKTargetInterrupt(struct TRKEvent* event);
extern int TRKTargetSupportRequest(void);
extern void TRKDestructEvent(struct TRKEvent* event);
extern void TRKGetInput(void);
extern u32 TRKTargetStopped(void);
extern int TRKTargetContinue(void);
extern unsigned char* gTRKInputPendingPtr;

void TRKNubMainLoop(void) {
    struct TRKEvent event;
    int exitRequested = 0;
    int inputPolled = 0;

    while (exitRequested == 0) {
        if (TRKGetNextEvent(&event) != 0) {
            inputPolled = 0;
            switch ((int)event.type) {
            case 0:
                break;
            case 2:
                TRKDispatchMessage(TRKGetBuffer((int)event.buffer_id));
                break;
            case 1:
                exitRequested = 1;
                break;
            case 3:
            case 4:
                TRKTargetInterrupt(&event);
                break;
            case 5:
                TRKTargetSupportRequest();
                break;
            default:
                break;
            }
            TRKDestructEvent(&event);
        } else if (inputPolled == 0 || *gTRKInputPendingPtr != 0) {
            inputPolled = 1;
            TRKGetInput();
        } else {
            if ((int)TRKTargetStopped() == 0) {
                TRKTargetContinue();
            }
            inputPolled = 0;
        }
    }
}
