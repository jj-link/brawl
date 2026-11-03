#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Packet { char pad[6]; u16 field6; } Packet;
typedef struct Callbacks { char pad[0x28]; void (*callback)(u16, int, struct Callbacks *); } Callbacks;
typedef struct Node { char pad0[8]; struct Node *next; char padc[8]; u16 id; char pad16[0x1a]; Callbacks *callbacks; } Node;
typedef struct Context { char pad0[8]; Node *nodes; char padc[0x2a]; u16 count36; char pad38[2]; u16 limit3a; u16 limit3c; u16 limit3e; u8 flag40; u8 flag41; char pad42[2]; Packet *queue; char pad48[4]; u16 count4c; } Context;
typedef struct Global { u8 level; char pad[3]; u16 count; } Global;
extern u8 lbl_8052CDC0[];
extern char lbl_80483840[];
extern void fn_802319FC(int, const char *, int);
extern void fn_802319E4(int, const char *);
extern void fn_8022F500(void *, void *);
extern void fn_8022F0E0(void *);
extern void *fn_8022F77C(void *);
extern u8 fn_8024CA8C(void *, void *);
extern u8 fn_8023DB4C(void *, u8 *);
extern void fn_8023D97C(int, void *, void *);
extern void fn_80231FB0(void *, int, int);

void fn_8024CB94(Context *self, void *unused, Packet *packet)
{
    const char *strings = lbl_80483840;
    Node *node;
    u8 state;
    struct { char pad[8]; u8 flag; } info;
    if (packet != 0) {
        if (self->count4c >= self->limit3a && self->flag41 == 0) {
            for (node = self->nodes; node != 0; node = node->next) {
                if (lbl_8052CDC0[0] >= 2)
                    fn_802319FC(0x80001, strings + 0xe4, node->id);
                if (node->callbacks->callback != 0) {
                    if (lbl_8052CDC0[0] >= 3)
                        fn_802319FC(0x80002, strings + 0x110, node->id);
                    node->callbacks->callback(node->id, 1, node->callbacks);
                }
            }
            self->flag41 = 1;
        }
        if (self->count4c <= self->limit3e) {
            packet->field6 = 0;
            fn_8022F500(&self->queue, packet);
        } else {
            fn_8022F0E0(packet);
            if (lbl_8052CDC0[0] >= 2)
                fn_802319E4(0x80001, strings + 0x150);
        }
    }
    if (self->flag40 == 0) {
        if (fn_8023DB4C((char *)self + 0x2a, &state) == 0 && state == 3 && self->count4c != 0) {
            info.flag = 0;
            fn_8023D97C(0x80, (void *)((unsigned long)self + 0x2a), &info);
            fn_80231FB0((char *)self + 0x10, 2, 1);
            return;
        }
        while ((*(u16 *)(lbl_8052CDC0 + 4)) != 0 && self->count36 != 0) {
            if (self->queue == 0 || self->queue->field6 != 0)
                break;
            if (self->flag40 != 0)
                return;
            packet = fn_8022F77C(&self->queue);
            if (packet == 0 || fn_8024CA8C(self, packet) == 0)
                break;
        }
        if (self->flag40 == 0) {
            if (self->count4c != 0 && self->count36 != 0)
                fn_80231FB0((char *)self + 0x10, 2, 2);
            if (self->flag41 != 0 && self->count4c <= self->limit3c) {
                node = self->nodes;
                self->flag41 = 0;
                for (; node != 0; node = node->next) {
                    if (node->callbacks->callback != 0) {
                        if (lbl_8052CDC0[0] >= 3)
                            fn_802319FC(0x80002, strings + 0x170, node->id);
                        node->callbacks->callback(node->id, 0, node->callbacks);
                        if (self->flag41 != 0)
                            break;
                    }
                }
            }
        }
    }
}