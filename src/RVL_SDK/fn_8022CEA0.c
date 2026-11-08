#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern int fn_803F6150(const void *, const void *, unsigned long);

typedef struct Node {
    char *data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct State {
    char pad[0x64];
    Node *head;
    Node *tail;
    Node nodes[10];
} State;

extern State lbl_804FB4A0;

void fn_8022CEA0(char *arg)
{
    Node *node;
    State *state = &lbl_804FB4A0;
    BOOL enabled = OSDisableInterrupts();
    char *cursor = (char *)state;
    int i;

    for (i = 0; i < 10; i++, cursor += 12) {
        if (fn_803F6150(((State *)cursor)->nodes[0].data + 0x40,
                        arg + 0x40, 6) == 0) {
            node = &state->nodes[i];

            if (fn_803F6150(state->head->data + 0x40,
                            node->data + 0x40, 6) != 0) {
                state->nodes[i].prev->next = state->nodes[i].next;

                if (fn_803F6150(state->tail->data + 0x40,
                                node->data + 0x40, 6) == 0) {
                    state->tail = state->nodes[i].prev;
                } else {
                    state->nodes[i].next->prev = state->nodes[i].prev;
                }

                state->nodes[i].next = state->head;
                state->head->prev = node;
                state->head = node;
                state->nodes[i].prev = 0;
            }
            break;
        }
    }

    OSRestoreInterrupts(enabled);
}