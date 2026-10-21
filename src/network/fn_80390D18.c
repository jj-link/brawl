#pragma force_active on
typedef struct Node {
    struct Node *next;
    char data[0x200];
} Node;

typedef struct Buffer {
    unsigned char pad[0x34];
    Node *head;
    signed char data[0x400];
} Buffer;

int fn_80390D18(Buffer *buffer, int start, int end)
{
    int offset;
    Node *node;

    if (start < end) {
        if (start < 0x400) {
            offset = start;
            node = 0;
        } else {
            int count = (start - 0x400) >> 9;
            node = buffer->head;
            while (count != 0) {
                node = node->next;
                --count;
            }
            offset = (start - 0x400) & 0x1FF;
        }

        for (; start < end; ++start) {
            char c;

            if (node == 0) {
                if (offset < 0x400) {
                    c = buffer->data[offset++];
                    goto test;
                }
                node = buffer->head;
                offset = 0;
            } else if (offset == 0x200) {
                offset = 0;
                node = node->next;
            }

            c = node->data[offset++];

test:
            if (c != 0x20)
                return start;
        }
    }

    return -1;
}
