#pragma force_active on
typedef struct {
    int unk0;
    int unk4;
    unsigned int unk8;
} FnObj;

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);

void *fn_8020999C(void *arg0) {
    FnObj *p = (FnObj *)arg0;
    int level = OSDisableInterrupts();
    p->unk8 = p->unk8 | 2;
    OSRestoreInterrupts(level);
    return arg0;
}
