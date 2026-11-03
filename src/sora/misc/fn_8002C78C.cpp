#pragma force_active on
extern "C" int fn_8002C614(void*, void*, unsigned char*);
extern "C" void stopMotorH__11gfPadSystemFi(void*, int);
extern "C" void stopMotor__11gfPadSystemFi(void*, int);
extern "C" void startMotor__11gfPadSystemFi(void*, int);

struct Node {
    Node* next;
};

struct Entry {
    unsigned char state;
    unsigned char new_state;
    unsigned char source;
    unsigned char pad0;
    unsigned short count;
    unsigned short pad1;
    Node* head;
};

struct Self {
    unsigned char pad[0x80];
    void* system;
    Entry entries[8];
    unsigned char pad2[2];
    unsigned char flag;
    unsigned char pad3;
    Node* free_list;
};

extern "C" void fn_8002C78C(Self* self) {
    Entry* entry = &self->entries[0];
    Node* node;
    Node* next;
    int i = 0;
    while (i < 8) {
        entry->new_state = 0;
        if (self->flag == 0) {
            entry->new_state = entry->source;
            node = entry->head;
            while (node != 0) {
                next = node->next;
                if (fn_8002C614(self, node, &entry->new_state) != 0) {
                    Node** prev = &entry->head;
                    while (*prev != node) {
                        prev = &(*prev)->next;
                    }
                    *prev = node->next;
                    entry->count--;
                    node->next = self->free_list;
                    self->free_list = node;
                }
                node = next;
            }
        }
        if (entry->new_state != entry->state) {
            switch (entry->new_state) {
            case 0:
                stopMotorH__11gfPadSystemFi(self->system, i);
                break;
            case 1:
                stopMotor__11gfPadSystemFi(self->system, i);
                break;
            case 2:
                startMotor__11gfPadSystemFi(self->system, i);
                break;
            }
            entry->state = entry->new_state;
        }
        i++;
        entry++;
    }
}