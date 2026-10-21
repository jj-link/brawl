#pragma force_active on
extern int OSRestoreInterrupts(int);

struct InterruptStack {
    unsigned char depth;
    int values[256];
};

extern struct InterruptStack lbl_804FD448;

int fn_80230508(void)
{
    unsigned char n = --lbl_804FD448.depth;
    return OSRestoreInterrupts(lbl_804FD448.values[n]);
}
