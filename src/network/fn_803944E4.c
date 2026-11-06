#pragma force_active on

typedef struct State {
    char pad[0x330];
    int status;
    int unk334;
    int active;
} State;

typedef struct Network {
    char pad[0x7D0];
    int socket;
} Network;

typedef struct Work {
    char pad[0x10];
    int enabled;
    char pad14[8];
    int field1C;
    char pad20[8];
    void *field28;
} Work;

typedef struct Context {
    int state;
    char pad4[0x28];
    Work *work;
} Context;

typedef struct Node {
    char pad[0xC];
    Context *context;
} Node;

typedef struct Entry {
    int state;
    int status;
} Entry;

extern void *fn_803974FC(void);
extern Network *fn_80397564(void *);
extern Node **fn_80397570(void *);
extern void *fn_80397580(void *);
extern Entry *fn_803970CC(void *, Context *);
extern int fn_80391F5C(void *, Context *, int);
extern void fn_803900E4(Network *, int);
extern void fn_8039094C(void *);
extern void fn_803900A0(void *);
extern void fn_80390950(void *);
extern void fn_80391888(void *, Context *);
extern void fn_803974A4(void *, Entry *);
extern void fn_80396E70(Entry *);

void fn_803944E4(State *self)
{
    void *root;
    Network *network;
    Node **slot;
    void *lock;
    Context *context;
    Work *work;
    Entry *entry;

    root = fn_803974FC();
    network = fn_80397564(root);
    slot = fn_80397570(root);
    lock = fn_80397580(root);
    context = (*slot)->context;
    work = context->work;
    entry = fn_803970CC(lock, context);
    if (context->state != 0) {
        self->status = 8;
        self->active = 0;
    }
    if (self->active == 0 && network->socket >= 0) {
        if (fn_80391F5C(lock, context, network->socket) < 0) {
            self->status = 10;
        }
        network->socket = -1;
    }
    if (self->status == 0) {
        work->enabled = 1;
    } else {
        work->enabled = 0;
        fn_803900E4(network, self->status);
        if (work->field28 == (char *)self + 0x104) {
            work->field28 = 0;
            work->field1C = 0;
        }
    }
    if (entry != 0) {
        entry->status = self->status;
    }
    fn_8039094C(lock);
    fn_803900A0(*slot);
    *slot = 0;
    fn_80390950(lock);
    fn_80391888(lock, context);
    if (entry != 0 && work->enabled != 0) {
        entry->state = 5;
    }
    fn_803974A4(lock, entry);
    if (entry != 0) {
        fn_80396E70(entry);
    }
}
