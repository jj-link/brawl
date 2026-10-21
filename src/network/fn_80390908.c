#pragma force_active on
void OSInitMutex(void *mutex);

typedef struct {
    unsigned char pad[0x18];
    int initialized;
} Obj;

void fn_80390908(Obj *self) {
    if (self->initialized == 0) {
        OSInitMutex(self);
        self->initialized = 1;
    }
}
