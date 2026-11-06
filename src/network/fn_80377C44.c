#pragma force_active on
typedef struct Entry {
    int offset;
    int size;
} Entry;

typedef struct State {
    char pad0[0x50];
    char *buffer;
    char pad54[0xC];
    void *table;
    char pad64[0x2C];
    int status;
} State;

extern int fn_80377028(State *, int, int, int *);
extern void fn_8037382C(void *, int, int);
extern int fn_8035A590(void *);
extern Entry *fn_8035A598(void *, int);
extern int fn_8037442C(State *, void *, int);
extern int fn_803777EC(void);

int fn_80377C44(State *self, int arg1, int arg2, int arg3) {
    int done;
    int result;
    Entry *entry;

    if (arg3 != 0) {
        if (fn_80377028(self, 0, arg2 + 7, &done) == 0) {
            return 0;
        }
        if (done != 0) {
            return 1;
        }

        fn_8037382C(&self->buffer, arg1, arg2);
        entry = fn_8035A598(self->table, fn_8035A590(self->table) - 1);

        if (fn_8037442C(self, self->buffer + entry->offset, entry->size) == 0) {
            result = 0;
        } else {
            result = 1;
            self->status = 0;
        }

        return result != 0;
    }
    return fn_803777EC();
}