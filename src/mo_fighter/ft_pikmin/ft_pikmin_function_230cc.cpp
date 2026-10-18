#pragma force_active on
struct PikminRecord {
    unsigned char data[0x74];
};

class PikminRecordProvider {
public:
    virtual void slot08();
    virtual PikminRecord* getRecord(int index);
};

struct PikminRecordHolder {
    unsigned char vptr[4];
    PikminRecordProvider* next;
    PikminRecord* array;
    int count;
};

extern "C" PikminRecord* fn_113_230CC(PikminRecordHolder* self, int index) {
    if (index >= self->count && self->next != 0) {
        return self->next->getRecord(index - self->count);
    }
    return &self->array[index];
}
