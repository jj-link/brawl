#pragma force_active on
extern unsigned int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(unsigned int);
extern int lbl_804F6810[];

typedef struct {
    unsigned char pad[0x8B8];
    int field;
} Obj;

int fn_8021A1E8(int idx) {
    unsigned int level = OSDisableInterrupts();
    Obj *p = (Obj *)lbl_804F6810[idx];
    int v = p->field;
    OSRestoreInterrupts(level);
    return v;
}
