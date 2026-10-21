#pragma force_active on
typedef unsigned int u32;

typedef struct Owner {
    unsigned char pad[0xC];
    void *field_C;
    void *field_10;
} Owner;

typedef struct State {
    unsigned char pad[8];
    Owner *owner;
    int state;
    int mode;
    unsigned char pad14[8];
    u32 start;
    u32 timeout;
} State;

extern void fn_80377AD0(State *);
extern void fn_8035B120(void *, State **);
extern void fn_8035A5C8(void *, State **);
extern int fn_80373AA0(State *, int, int, int);

int fn_80374488(State *self, u32 now)
{
    State *local;
    int expired;

    if (self->state < 5) {
        expired = 0;
        if (self->mode != 0) {
            if (self->timeout != 0 && now - self->start > self->timeout) {
                expired = 1;
            }
        } else if (self->state < 4 && now - self->start > 60000U) {
            expired = 1;
        }

        if (expired != 0) {
            fn_80377AD0(self);
            local = self;
            if (self->state != 7) {
                self->state = 7;
                fn_8035B120(local->owner->field_C, &local);
                fn_8035A5C8(local->owner->field_10, &local);
            }
            if (fn_80373AA0(self, 6, 0, 0) == 0) {
                return 0;
            }
        }
    }
    return 1;
}
