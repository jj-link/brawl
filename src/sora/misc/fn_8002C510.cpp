#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;

struct Node {
    Node* next;
    int value;
    u8 type;
    u8 field9;
    u8 priority;
    u8 fieldB;
    u16 fieldC;
    u16 fieldE;
    int data;
    int field14;
    u16* current;
    u16* start;
};

struct Owner {
    char padding[0xE4];
    u16 limit;
    u16 paddingE6;
    Node* freeList;
};

struct Channel {
    char padding[0x88];
    u16 count;
    u16 padding8A;
    Node* head;
};

extern "C" int OSDisableInterrupts();
extern "C" int OSRestoreInterrupts(int);

extern "C" int fn_8002C510(
    Owner* self, int index, int value, int data,
    u8 priority, u16* input, signed char type)
{
    if (((*input >> 13) & 7) == 0)
        return 0;

    Channel* channel = (Channel*)((char*)self + index * 12);
    int result = 0;
    int interrupts = OSDisableInterrupts();
    Node* next;
    Node** link;
    Node* node = self->freeList;

    if (node != 0 && channel->count < self->limit) {
        link = &channel->head;
        self->freeList = node->next;
        node->value = value;
        node->type = type;
        node->field9 = 0;
        node->priority = priority;
        node->fieldB = 0;
        node->fieldC = 0;
        node->fieldE = 0;
        node->data = data;
        node->field14 = 0;
        node->current = node->start = input;

        while ((next = *link) != 0 && next->priority <= node->priority) {
            link = &next->next;
        }

        node->next = next;
        result = 1;
        *link = node;
        channel->count++;
    }

    OSRestoreInterrupts(interrupts);
    return result;
}
