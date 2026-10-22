#include <types.h>
#pragma force_active on

struct EventNode;

struct NodeBase {
    EventNode* m_next;
};

struct EventNode : NodeBase {
    virtual void process() = 0;
};

struct Container {
    u8 pad0[0x14];
    s32 m_state;
    u8 pad1[0x8];
    EventNode* m_list20;
    EventNode* m_list24;
    EventNode* m_list28;
    u8 m_flag2C;
};

extern "C" void fn_27_233CFC(void* arg0) {
    Container* self = (Container*)arg0;

    if (self->m_flag2C == 1) {
        if (self->m_state == 0 || self->m_state == 3) {
            self->m_state = 1;
        } else {
            self->m_state = 2;
        }
    } else {
        if ((u32)(self->m_state - 1) <= 1) {
            self->m_state = 3;
        } else {
            self->m_state = 0;
        }
    }

    switch (self->m_state) {
    case 1: {
        EventNode* node = self->m_list24;
        if (node) {
            node->process();
            node = node->m_next;
            while (node) {
                node->process();
                node = node->m_next;
            }
        }
        node = self->m_list20;
        if (node) {
            node->process();
            node = node->m_next;
            while (node) {
                node->process();
                node = node->m_next;
            }
        }
        break;
    }
    case 2: {
        EventNode* node = self->m_list20;
        if (node) {
            node->process();
            node = node->m_next;
            while (node) {
                node->process();
                node = node->m_next;
            }
        }
        break;
    }
    case 3: {
        EventNode* node = self->m_list28;
        if (node) {
            node->process();
            node = node->m_next;
            while (node) {
                node->process();
                node = node->m_next;
            }
        }
        break;
    }
    }
}