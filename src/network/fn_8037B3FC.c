#pragma force_active on
typedef struct Buffer {
    int owner;
    char *data;
    int capacity;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
} Buffer;

extern char *fn_8035DFF8(char *, int);

static int allocate(Buffer *buffer, int size)
{
    char *data;

    if (buffer == 0) return 0;
    if (size <= 0) return 0;

    data = fn_8035DFF8(0, size);
    if (data == 0) return 0;

    buffer->data = data;
    buffer->capacity = size;
    return 1;
}

int fn_8037B3FC(int owner, Buffer *buffer, int size, int limit)
{
    if (owner == 0) return 0;
    if (buffer == 0) return 0;
    if (size <= 0) return 0;
    if (limit <= 0) return 0;

    buffer->owner = owner;
    buffer->data = 0;
    buffer->capacity = 0;
    buffer->fieldC = 0;
    buffer->field10 = 0;
    buffer->field14 = limit;
    buffer->field18 = 0;
    buffer->field1C = 0;
    buffer->field20 = 0;

    if (!allocate(buffer, size)) return 0;

    *buffer->data = 0;
    return 1;
}
