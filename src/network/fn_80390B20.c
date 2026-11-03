#pragma force_active on

typedef struct Node {
    struct Node *next;
    signed char data[0x200];
} Node;

typedef struct Buffer {
    char pad[0x34];
    Node *head;
    signed char data[0x400];
} Buffer;

int fn_80390B20(Buffer *buffer, int start, int end, int *out1, int *out2)
{
    int val;
    signed char c;
    Node *node;
    int offset;
    int flag;

    if (out1 != 0) {
        *out1 = -1;
    }

    if (start < end) {
        val = -1;
        flag = 0;

        if (start < 0x400) {
            offset = start;
            node = 0;
        } else {
            int count = (start - 0x400) >> 9;

            node = buffer->head;
            while (count != 0) {
                node = node->next;
                count--;
            }
            offset = (start - 0x400) & 0x1FF;
        }

        for (; start < end; start++) {
            if (node == 0) {
                if (offset < 0x400) {
                    c = (signed char)((unsigned char *)buffer->data)[offset++];
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
            if (c == 0x3A && out1 != 0 && *out1 < 0) {
                *out1 = start;
            }

            if (flag != 0) {
                if (c == 0x0A) {
                    val = start == end - 1 ? 0 : start + 1;
                    if (out2 != 0) {
                        *out2 = 2;
                    }
                }
                return val;
            }

            if (c == 0x0D) {
                val = start == end - 1 ? 0 : start + 1;
                flag = 1;
                if (out2 != 0) {
                    *out2 = 1;
                }
            }

            if (c == 0x0A) {
                val = start == end - 1 ? 0 : start + 1;
                if (out2 != 0) {
                    *out2 = 1;
                }
                return val;
            }
        }
    }

    return -1;
}
