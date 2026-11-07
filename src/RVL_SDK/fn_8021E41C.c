#include <revolution/OS/OSInterrupt.h>
#include <string.h>
#pragma force_active on

typedef struct {
    unsigned char a;
    unsigned char b;
    void *data;
    unsigned int count;
} Object;

void fn_8021E41C(Object *obj)
{
    BOOL level = OSDisableInterrupts();
    obj->a = 0;
    obj->b = 0;
    memset(obj->data, 0, obj->count * 0x30);
    OSRestoreInterrupts(level);
}