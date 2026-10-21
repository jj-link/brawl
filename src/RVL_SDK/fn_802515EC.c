#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Packet {
    u8 pad[2];
    u16 size;
} Packet;

typedef struct Target {
    u8 pad[0x71];
    u8 ready;
} Target;

typedef struct State {
    u8 pad0[0xD];
    u8 channel;
    u8 padE[0xA];
    u8 list[0xC];
    u8 flag;
    u8 pad25[3];
    s32 remaining;
    u8 pad2C[0x40];
    Target *target;
    u8 pad70[0x18];
    u32 mask;
} State;

extern u8 lbl_8052D5A8[];
extern const char lbl_80484154[];

extern Packet *fn_8022F77C(void *);
extern void fn_802319E4(u32, const char *);
extern void fn_80254A5C(void *, u16, void *);
extern u32 fn_80251BAC(void *);

u32 fn_802515EC(State *self)
{
    u32 result = 0;

    if (self->remaining != 0) {
        while (self->flag == 0 &&
               self->target != 0 &&
               self->target->ready != 0) {
            Packet *packet = fn_8022F77C(self->list);

            if (packet != 0) {
                if (lbl_8052D5A8[0x414] >= 4U) {
                    fn_802319E4(0x90003, lbl_80484154);
                }

                self->remaining -= packet->size;
                fn_80254A5C(self->target, self->channel, packet);
                result |= 0x4000;

                if (self->remaining == 0) {
                    result |= 4;
                    break;
                }
            } else {
                result |= 4;
                break;
            }
        }

        result |= fn_80251BAC(self);
    }

    return result & self->mask;
}
