#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Data {
    char pad[0x4d];
    u8 flag;
};

struct Node {
    void* unk0;
    Node* next;
    Data* data;
};

struct Owner {
    char pad0[0x40];
    Node* head;     // 0x40
    char pad44[4];  // 0x44
    Node* cur;      // 0x48
    u32 count;      // 0x4c
};

extern "C" {
void fn_27_271BF0(Data* data);

void fn_27_2718C8(Owner* self) {
    u32 n = self->count;
    u32 i = 0;
    self->cur = self->head;
    for (; i < n; i++) {
        if (self->cur->data->flag == 0) {
            fn_27_271BF0(self->cur->data);
            self->cur = self->cur->next;
        }
    }
}
}
