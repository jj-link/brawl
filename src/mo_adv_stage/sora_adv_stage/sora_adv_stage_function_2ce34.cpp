#include <string.h>
#pragma force_active on

extern "C" void createSoundWork__9grGimmickFUlUl(void*, unsigned long, unsigned long);
extern "C" const float lbl_40_rodata_4F0;

struct Pair {
    int a;
    int b;
};

struct Vec2 {
    float x;
    float y;

    Vec2() {}
    Vec2(const Vec2& v) {
        *(Pair*)this = *(const Pair*)&v;
    }
};

struct Effect {
    int pad0[3];
    int id;
    int repeat;
    int end;
    unsigned short node;
    unsigned short generator;
    Vec2 offset;
    float scale;
};

struct Rec {
    int count;
    unsigned short first;
    unsigned short pad;
    unsigned short second;
    unsigned short pad2;
};

struct Data {
    char pad[0x150];
    int sub;
    unsigned short s154;
    unsigned short s156;
    unsigned short s158;
    Rec recs[4];
    char pad2[0x30];
    int flag1bc;
};

struct Self {
    char pad[0xa8];
    Effect* effects;
    char pad2[0xa4];
    Data* data;
};

struct LocalEntry {
    int id;
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
};

inline void setBasicSound(Self* self, int index, int id, const Vec2& v) {
    self->effects[index].id = id;
    self->effects[index].repeat = 0;
    self->effects[index].node = 0;
    self->effects[index].end = 0;
    self->effects[index].offset = v;
}

inline void setSpecialSound(Self* self, Data* data, Vec2 v) {
    int id = data->sub;
    if (id > 0) {
        self->effects[10].id = id;
        self->effects[10].repeat = data->s154;
        self->effects[10].node = data->s156;
        self->effects[10].end = data->s158;
        self->effects[10].generator = 0;
        self->effects[10].offset = v;
    }
}

inline void setLoopSound(Self* self, int dstOffset, LocalEntry& local, Vec2 v) {
    if (local.id > 0) {
        *(int*)((char*)self->effects + dstOffset + 0x34) = local.id;
        *(int*)((char*)self->effects + dstOffset + 0x38) = local.a;
        *(unsigned short*)((char*)self->effects + dstOffset + 0x40) = local.b;
        *(int*)((char*)self->effects + dstOffset + 0x3c) = local.c;
        *(unsigned short*)((char*)self->effects + dstOffset + 0x42) = 0;
        Vec2* dest = (Vec2*)((unsigned long)dstOffset + (unsigned long)self->effects + 0x44);
        *dest = v;
    }
}

inline void setLoopWrapper(Self* self, int dstOffset, LocalEntry& local, const Vec2& v) {
    setLoopSound(self, dstOffset, local, v);
}

extern "C" void fn_40_2CE34(Self* self) {
    createSoundWork__9grGimmickFUlUl(self, 0xb, 1);

    Vec2 l0_0, v0;
    self->effects[0].id = 0x226f;
    v0.x = lbl_40_rodata_4F0;
    self->effects[0].repeat = 0;
    v0.y = lbl_40_rodata_4F0;
    self->effects[0].node = 0;
    *(Pair*)&l0_0 = *(const Pair*)&v0;
    self->effects[0].end = 0;
    self->effects[0].offset = l0_0;

    LocalEntry local;
    memset(&local, 0, 0xc);

    int srcOffset;
    int dstOffset;
    unsigned index = 0;
    srcOffset = 0;
    dstOffset = 0;
    for (; index < 4; ++index) {
        Rec* rec = (Rec*)((char*)self->data + 0x15c + srcOffset);
        if (rec->count > 0) {
            local.a = rec->first;
            local.c = ((Rec*)((char*)self->data + 0x15c + srcOffset))->second;

            if (index >= 1) {
                Vec2 l0A, vA;
                vA.x = lbl_40_rodata_4F0;
                vA.y = lbl_40_rodata_4F0;
                local.id = 0x2271;
                local.c = 0;
                *(Pair*)&l0A = *(const Pair*)&vA;
                if (local.id > 0) {
                    *(int*)((char*)self->effects + dstOffset + 0xac) = local.id;
                    *(int*)((char*)self->effects + dstOffset + 0xb0) = local.a;
                    *(unsigned short*)((char*)self->effects + dstOffset + 0xb8) = local.b;
                    *(int*)((char*)self->effects + dstOffset + 0xb4) = local.c;
                    *(unsigned short*)((char*)self->effects + dstOffset + 0xba) = 0;
                    Vec2* dest = (Vec2*)((unsigned long)dstOffset + (unsigned long)self->effects + 0xbc);
                    *dest = l0A;
                }
                local.a += 0x1e;
                local.c = ((Rec*)((char*)self->data + 0x15c + srcOffset))->second - 0x1e;
            }

            Vec2 vB;
            vB.x = lbl_40_rodata_4F0;
            vB.y = lbl_40_rodata_4F0;
            local.id = 0x2270;
            setLoopWrapper(self, dstOffset, local, vB);
        }
        srcOffset += 12;
        dstOffset += 40;
    }

    Vec2 v9;
    Vec2 v8;
    Vec2 v10;
    Vec2 c8;
    v9.x = lbl_40_rodata_4F0;
    v9.y = lbl_40_rodata_4F0;
    setBasicSound(self, 9, 0x2273, Vec2(v9));

    if (self->data->flag1bc > 0) {
        v8.x = lbl_40_rodata_4F0;
        v8.y = lbl_40_rodata_4F0;
        *(Pair*)&c8 = *(const Pair*)&v8;
        setBasicSound(self, 8, 0x2272, c8);
    }

    v10.x = lbl_40_rodata_4F0;
    v10.y = lbl_40_rodata_4F0;
    setSpecialSound(self, self->data, v10);
}
