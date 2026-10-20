#pragma force_active on
struct PikminArticleRecordProvider {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual bool isEmpty();
    virtual void slot1C();
    virtual void advance();
};

struct PikminArticleRecordHolder : PikminArticleRecordProvider {
    PikminArticleRecordProvider* next;
    int* array;
    int count;
};

extern "C" void fn_113_22F0C(PikminArticleRecordHolder* self) {
    if (self->isEmpty()) {
        return;
    }

    if (self->count > 0) {
        int count = self->count - 1;
        self->count = count;
        if (count <= 0) {
            self->array = 0;
        } else {
            self->array = (int*)((char*)self->array + 0x74);
        }
    } else if (self->next != 0) {
        self->next->advance();
    }
}
