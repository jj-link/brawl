#pragma force_active on
typedef int BOOL;

extern BOOL OSRestoreInterrupts(BOOL status);

BOOL fn_80406478(BOOL *arg0) {
    return OSRestoreInterrupts(*arg0);
}
