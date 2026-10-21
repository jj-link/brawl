#pragma force_active on
typedef struct Descriptor {
    unsigned char pad[0x40];
    int type;
    int size;
} Descriptor;

typedef struct Object {
    unsigned char pad0[8];
    Descriptor *descriptor;
    int state;
    unsigned char pad10[0x88];
    int handle;
} Object;

extern void fn_80378B50(void **, int *);
extern int fn_8035A590(int);
extern void fn_80373DCC(Object *, int, void *, int, int);
extern int fn_80377C44(Object *, void *, int, int);
extern void *memcpy(void *, const void *, unsigned long);

int fn_80374AC4(Object *self, void *data, int length, int flag)
{
    unsigned short value;
    int success;
    int result;

    if (self->state != 5) {
        return 8;
    }

    fn_80378B50(&data, &length);

    if (flag != 0 && self->descriptor->type == 2) {
        memcpy(&value, data, 2);
        if (length != value + self->descriptor->size) {
            return 9;
        }
    }

    if (fn_8035A590(self->handle) != 0) {
        fn_80373DCC(self, 0, data, length, flag);
        return 0;
    }

    success = fn_80377C44(self, data, length, flag);
    result = 10;
    if (success != 0) {
        result = 0;
    }
    return result;
}
