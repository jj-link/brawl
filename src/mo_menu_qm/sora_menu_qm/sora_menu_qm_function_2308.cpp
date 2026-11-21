#include <mu/mu_object.h>
#include <mu/mu_msg.h>
#include <string.h>

#pragma force_active on

extern "C" {
const char* getMsgData__5MuMsgFUlPPv(MuMsg*, unsigned long, void**);
void fn_800B7AA4(MuObject*, float, unsigned char);
void fn_800B3C5C(MuObject*, void*, int);
void fn_800B92D8(MuMsg*, unsigned long, char*, unsigned long);
void fn_4_35C(void*, int);
extern char lbl_4_data_210[];
}

struct Self {
    char pad0[0xfc];
    MuMsg* msg;
    char pad1[0x1d8];
    MuObject* a;
    MuObject* b;
    MuObject* c;
    MuObject* d;
    MuObject* e;
    char pad2[0x88];
    unsigned long min;
    unsigned long max;
    unsigned long mode;
    unsigned long count;
    int selected;
};

static void forceConstants(MuObject* object)
{
    object->setFrameNode(5.0f);
    object->setFrameNode(2.0f);
    object->setFrameNode(1.0f);
    object->setFrameNode(3.0f);
    object->setFrameNode(-1.0f);
    object->setFrameNode(0.0f);
    object->setFrameNode(4.0f);
    object->setFrameNode(9.0f);
}

extern "C" void fn_4_2308(Self* self, int update, int visible)
{
    char buf[0x100];
    unsigned long size;
    unsigned long pos;
    const char* data;

    (void)5.0f;
    (void)2.0f;
    (void)1.0f;
    (void)3.0f;
    (void)-1.0f;
    (void)0.0f;
    (void)4.0f;
    (void)9.0f;
    if (self->selected == 0) {
        self->c->setFrameNode(0.0f);
        self->d->setFrameNode(1.0f);
        self->msg->printIndex(0, 2, 0);
    } else {
        self->c->setFrameNode(1.0f);
        self->d->setFrameNode(0.0f);
        self->msg->printIndex(0, 3, 0);
    }

    if (self->mode == 0) {
        self->c->setFrameVisible(2.0f);
        self->msg->printIndex(2, 8, 0);
    } else {
        self->c->setFrameVisible(1.0f);
        self->msg->printIndex(2, 9, 0);
    }

    if (self->count == 1) {
        self->d->setFrameVisible(2.0f);
    } else if (self->count == self->min) {
        self->d->setFrameVisible(1.0f);
    } else {
        self->d->setFrameVisible(3.0f);
    }

    fn_800B7AA4(self->e, (float)self->count, 6);
    memset(buf, 0, 0x100);

    data = getMsgData__5MuMsgFUlPPv(self->msg, self->mode + 0x14, (void**)&size);
    memcpy(buf, data, size);
    pos = size;

    data = getMsgData__5MuMsgFUlPPv(self->msg, self->count + 0x1f, (void**)&size);
    memcpy(buf + pos, data, size);
    pos += size;

    data = getMsgData__5MuMsgFUlPPv(self->msg, 0x16, (void**)&size);
    memcpy(buf + pos, data, size);
    fn_800B92D8(self->msg, 1, buf, pos + size);

    if (update) {
        if (self->count > self->max - self->min) {
            fn_800B3C5C(self->a, lbl_4_data_210 + (self->max - self->min - 1) * 20, 1);
            fn_800B3C5C(self->b, lbl_4_data_210 + (self->max - self->min + 4) * 20, 1);
        } else {
            fn_800B3C5C(self->a, lbl_4_data_210 + (self->count - 1) * 20, 1);
            fn_800B3C5C(self->b, lbl_4_data_210 + (self->count + 4) * 20, 1);
        }
    }

    if (visible) {
        self->a->setFrameVisible((float)self->min);
        self->b->setFrameVisible((float)(self->max - self->min));
        fn_4_35C(self, 3);
    }
}
