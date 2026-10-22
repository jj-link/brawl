#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern int fn_8020CAEC(int);
extern char *strcpy(char *, const char *);
extern char lbl_8047C120[];

typedef struct Obj {
    int field0;
    void (*cb)(int, void *);
} Obj;

void fn_8020D294(int arg0, int arg1) {
    Obj *obj = (Obj *)arg1;
    if (arg0 == 0) {
        arg1 = OSDisableInterrupts();
        strcpy(lbl_8047C120, (char *)obj + 0x34);
        OSRestoreInterrupts(arg1);
    }
    obj->cb(fn_8020CAEC(arg0), obj);
}