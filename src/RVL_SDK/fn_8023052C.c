#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

u32 OSDisableInterrupts(void);

struct InterruptStack {
    u8 depth;
    u32 values[1];
    u8 pad[0x2ABA - 8];
};

extern struct InterruptStack lbl_804FD448;

void fn_8023052C(void) {
    lbl_804FD448.values[lbl_804FD448.depth] = OSDisableInterrupts();
    lbl_804FD448.depth++;
}
