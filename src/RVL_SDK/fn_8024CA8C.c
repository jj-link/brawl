#pragma force_active on
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct State {
    u8 pad[0x36];
    u16 remaining;
    u16 used;
    u8 pad3A[6];
    u8 flag;
} State;

typedef struct Packet {
    u16 command;
    u16 size;
    u16 unk4;
    u16 count;
} Packet;

typedef struct Config {
    u8 pad[0x7C];
    u16 unit;
    u16 limit;
    u8 tail[8];
} Config;

typedef struct Pool {
    u8 pad[4];
    u16 remaining;
    u8 tail[0x7E2];
} Pool;

extern Config lbl_805297D0;
extern Pool lbl_8052CDC0;
extern void fn_80231844(void *, short);

int fn_8024CA8C(State *state, Packet *packet)
{
    u16 count;

    if (packet->size <= lbl_805297D0.limit) {
        state->remaining--;
        state->used++;
        lbl_8052CDC0.remaining--;
        fn_80231844(packet, 0x2100);
    } else {
        count = (packet->size + lbl_805297D0.unit - 5) /
                lbl_805297D0.unit;

        if (count > lbl_8052CDC0.remaining) {
            count = lbl_8052CDC0.remaining;
            packet->count = count;
            state->flag = 1;
        }

        if (count > state->remaining) {
            count = state->remaining;
            packet->count = count;
            state->flag = 1;
        }

        lbl_8052CDC0.remaining -= count;
        state->remaining -= count;
        state->used += count;
        fn_80231844(packet, 0x2100);
    }

    return 1;
}
