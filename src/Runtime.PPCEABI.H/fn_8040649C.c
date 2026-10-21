#pragma force_active on
typedef unsigned int BOOL;

extern BOOL OSDisableInterrupts(void);

void fn_8040649C(BOOL* arg0) {
    *arg0 = OSDisableInterrupts();
}
