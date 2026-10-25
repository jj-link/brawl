#pragma force_active on
struct Node {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int size();
};
struct Container {
    void* vtable;
    Node* next;
    int active;
    int count;
};
extern "C" int fn_27_C7974(const Container* self) {
    int count = self->count;
    if (self->active == 0) count = 0;
    if (self->next) return count + self->next->size();
    return count;
}
