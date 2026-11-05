#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
void getNodeIndex__6GroundFPUlUlPCc(void* self, u32* out, u32 flag, const char* name);
void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);
extern char lbl_48_data_7A8[];
}

struct Node {
    u32 f0;
    u32 f4;
    float f8;
    float fC;
    float f10;
    char pad14[0x6C];
    u32 f80;
    u32 f84;
    float f88;
    float f8C;
    float f90;
    char pad94[0x6C];
    u32 f100;
    u32 f104;
    float f108;
    float f10C;
    float f110;
};

struct Sub {
    virtual void fn_48_6260();
    virtual void fn_48_5728();
    virtual void fn_48_5738();
    virtual void fn_48_B6A4();
    virtual void fn_48_3DF8(int, int);

    Node* node;
    u32 state;
    u32 unkC;
};

extern "C" void fn_48_2714(void* self) {
    char* base = lbl_48_data_7A8;
    Sub* sub = (Sub*)((char*)self + 0xD0);
    if (sub == 0) {
        return;
    }
    void** models = *(void***)((char*)self + 0x44);
    char* mdl = (char*)models[0];
    if (mdl == 0) {
        return;
    }
    switch (*((u8*)self + 0x190)) {
    case 0:
        if (sub->node == 0) {
            if (sub == 0) {
                return;
            }
            sub->state = 3;
            sub->fn_48_3DF8(0, 15);
            sub->node->f4 |= 1;
            sub->node->f84 |= 1;
            sub->node->f104 |= 1;
        }
        if (*(void**)(mdl + 0x11C) == 0) {
            sub->unkC = 0;
            getNodeIndex__6GroundFPUlUlPCc(self, (u32*)sub->node, 0, base + 0xB0);
            getNodeIndex__6GroundFPUlUlPCc(self, (u32*)((char*)sub->node + 0x80), 0, base + 0xB8);
            getNodeIndex__6GroundFPUlUlPCc(self, (u32*)((char*)sub->node + 0x100), 0, base + 0xC0);
            *(void**)(mdl + 0x11C) = sub;
            EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(mdl, 1);
            *(short*)(mdl + 0x122) = (short)sub->node->f0;
        }
        {
            Node* node = sub->node;
            float* src = *(float**)((char*)self + 0x15C);
            node->f8 = src[0];
            node->fC = src[1];
            node->f10 = src[2];
        }
        {
            Node* node = sub->node;
            float* src = *(float**)((char*)self + 0x15C);
            node->f88 = src[3];
            node->f8C = src[4];
            node->f90 = src[5];
        }
        {
            Node* node = sub->node;
            float* src = *(float**)((char*)self + 0x15C);
            node->f108 = src[6];
            node->f10C = src[7];
            node->f110 = src[8];
        }
        break;
    case 1:
        if (sub->node == 0) {
            if (sub == 0) {
                return;
            }
            sub->state = 2;
            sub->fn_48_3DF8(0, 15);
            sub->node->f4 |= 1;
            sub->node->f84 |= 1;
        }
        if (*(void**)(mdl + 0x11C) == 0) {
            sub->unkC = 0;
            getNodeIndex__6GroundFPUlUlPCc(self, (u32*)sub->node, 0, base + 0xB0);
            getNodeIndex__6GroundFPUlUlPCc(self, (u32*)((char*)sub->node + 0x80), 0, base + 0xB8);
            *(void**)(mdl + 0x11C) = sub;
            EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(mdl, 1);
            *(short*)(mdl + 0x122) = (short)sub->node->f0;
        }
        {
            Node* node = sub->node;
            float* src = *(float**)((char*)self + 0x15C);
            node->f8 = src[0];
            node->fC = src[1];
            node->f10 = src[2];
        }
        {
            Node* node = sub->node;
            float* src = *(float**)((char*)self + 0x15C);
            node->f88 = src[3];
            node->f8C = src[4];
            node->f90 = src[5];
        }
        break;
    }
}
