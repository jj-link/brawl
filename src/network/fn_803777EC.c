#pragma force_active on

typedef struct Config {
    char pad[0x40];
    int mode;
    int offset;
} Config;

typedef struct State {
    char pad0[8];
    Config *config;
    char padC[0x44];
    char *buffer;
    int capacity;
    int length;
} State;

extern short lbl_8059F980;
extern int fn_803F6150(const void *, const void *, unsigned long);
extern int fn_8037442C(State *, void *, int);
extern int fn_803737D8(void *);
extern void fn_8037382C(void *, const void *, int);
extern void fn_803738B8(void *, int, int);

int fn_803777EC(State *self, char *data, int size)
{
    int total;
    char *start;
    int offset;

    if (size < 2 || fn_803F6150(data + self->config->offset, &lbl_8059F980, 2) != 0) {
        if (fn_8037442C(self, data, size) == 0) {
            return 0;
        }
        return 1;
    }
    total = size + 2;
    if (fn_803737D8(&self->buffer) < total) {
        return 1;
    }
    start = self->buffer + self->length;
    if (self->config->mode == 2) {
        fn_8037382C(&self->buffer, data, 2);
    }
    fn_8037382C(&self->buffer, &lbl_8059F980, 2);
    offset = self->config->offset;
    fn_8037382C(&self->buffer, data + offset, size - offset);
    if (fn_8037442C(self, start, total) == 0) {
        return 0;
    }
    fn_803738B8(&self->buffer, -1, total);
    return 1;
}
