#include <revolution/OS/OSInterrupt.h>
#pragma force_active on
struct Entry { int value; char pad[0x2c]; char data[8]; };
struct Object {
char pad0[0x80]; unsigned char mode, active; char pad82[0x1e]; int stride; char padA4[4]; int base; char padAC[0x17]; unsigned char flagC3; char padC4; unsigned char flagC5; char padC6[0x26]; int count; char padF0[0x6d0]; unsigned char* device; int channels; char pad7C8[4]; Entry entries[1];
};
extern "C" void fn_801D17F4(unsigned char*, int, int, int);
extern "C" void fn_801D1868(unsigned char*, int, int, int);
extern "C" void fn_801D18DC(unsigned char*, unsigned int);
extern "C" int fn_801D1230(void*);
extern "C" void fn_801D19D8(int*, int);
extern "C" void fn_801D1760(unsigned char*, int, int);
extern "C" void fn_801D1964(unsigned char*, int, int, int);
extern "C" void fn_801CED50(Object* self, int index) {
    BOOL enabled;
    BOOL enabled2;
    BOOL otherEnabled;
    int nextOffset;
    int current;
    Object* p2;
    int i;
    int j2;
    Object* entry;
    int next;
    if (self->active) {
        next = index + 1;
        if (next >= self->count) next -= self->count;
        enabled = OSDisableInterrupts();
        int stride = self->stride;
        current = self->base + index * stride;
        nextOffset = next * stride;
        enabled2 = OSDisableInterrupts();
        entry = self;
        for (i = 0; i < self->channels; entry = (Object*)((char*)entry + 0x38), i++) {
            fn_801D17F4(self->device, i, entry->entries[0].value, nextOffset);
            fn_801D1868(self->device, i, entry->entries[0].value, current);
        }
        fn_801D18DC(self->device, 1);
        OSRestoreInterrupts(enabled2);
        if (self->mode == 2) {
            if (fn_801D1230(self->device) == 0) {
                fn_801D19D8((int*)self->device, 0);
                int j;
                char* data = self->entries[0].data;
                for (j = 0; j < self->channels; data += 0x38, j++) {
                    fn_801D1760(self->device, j, (int)data);
                }
            }
            if (index == self->count - 1) self->flagC3 = 1;
        }
        OSRestoreInterrupts(enabled);
    } else {
        otherEnabled = OSDisableInterrupts();
        {
            p2 = self;
            for (j2 = 0; j2 < self->channels; p2 = (Object*)((char*)p2 + 0x38), j2++) {
                fn_801D1964(self->device, j2, p2->entries[0].value, self->base + index * self->stride);
            }
        }
        OSRestoreInterrupts(otherEnabled);
        self->flagC5 = 1;
    }
}