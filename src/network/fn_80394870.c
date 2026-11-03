#pragma force_active on

typedef struct Context {
    int state;
    int unk4;
    int unk8;
    int error;
} Context;

typedef struct Node {
    char pad[0xC];
    Context *context;
    int socket;
} Node;

typedef struct Network {
    char pad[0x7D0];
    int socket;
} Network;

typedef struct Self {
    char pad[0x314];
    int address;
    int unk318;
    int port;
    char pad320[0x10];
    int status;
    int unk334;
    int active;
} Self;

extern void *fn_803974FC(void);
extern Network *fn_80397564(void *);
extern Node **fn_80397570(void *);
extern void *fn_80397580(void *);
extern int fn_80391F5C(void *, Context *, int);
extern int fn_80391ED0(Context *);
extern void fn_8039094C(void *);
extern void fn_80390950(void *);
extern int fn_80391FC8(Network *, void *, Context *, int, int, int);
extern int fn_803900F4(Network *);

int fn_80394870(Self *self)
{
    void *root;
    Network *network;
    Node **slot;
    Context *context;
    void *lock;
    int result;

    root = fn_803974FC();
    network = fn_80397564(root);
    slot = fn_80397570(root);
    context = (*slot)->context;
    lock = fn_80397580(root);
    if (self->active == 0) {
        if (network->socket >= 0 && fn_80391F5C(lock, context, network->socket) < 0) {
            network->socket = -1;
            self->status = 10;
            return 0;
        }
        result = fn_80391ED0(context);
        network->socket = result;
        if (result < 0) {
            self->status = 3;
            return 0;
        }
        fn_8039094C(lock);
        (*slot)->socket = network->socket;
        fn_80390950(lock);
        if (context->state != 0) {
            return 0;
        }
        if (fn_80391FC8(network, lock, context, network->socket, self->address, self->port) < 0) {
            if (context->error != 0) {
                self->status = 13;
                return 0;
            }
            if (fn_803900F4(network) != 0) {
                self->status = 14;
                return 0;
            }
            self->status = 5;
            return 0;
        }
    } else {
        fn_8039094C(lock);
        (*slot)->socket = network->socket;
        fn_80390950(lock);
    }
    return 1;
}
