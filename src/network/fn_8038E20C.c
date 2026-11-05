#pragma force_active on
typedef struct Data {
    int tableid;
    void *fields;
    int count;
} Data;

typedef struct Self {
    char pad[8];
    Data *data;
    char pad2[12];
    int id;
} Self;

extern char lbl_8059FC00[4];
extern char lbl_8059FC20[8];
extern void fn_803646CC(int, const char *, const char *, int);
extern void fn_8038DEA0(Self *, void *, int);

int fn_8038E20C(Self *self) {
    Data *data = self->data;
    fn_803646CC(self->id, lbl_8059FC00, lbl_8059FC20, data->tableid);
    fn_8038DEA0(self, data->fields, data->count);
    return 0;
}