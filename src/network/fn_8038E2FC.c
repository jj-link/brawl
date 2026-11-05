#pragma force_active on
typedef struct Data {
    int tableid;
    int recordid;
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
extern char lbl_80491088[];
extern void fn_803646CC(int, const char *, const char *, int);
extern void fn_80365548(int, const char *, const char *, int);
extern void fn_8038DEA0(Self *, void *, int);
int fn_8038E2FC(Self *self) {
    Data *data = self->data;
    fn_803646CC(self->id, lbl_8059FC00, lbl_8059FC20, data->tableid);
    fn_80365548(self->id, lbl_8059FC00, lbl_80491088, data->recordid);
    fn_8038DEA0(self, data->fields, data->count);
    return 0;
}