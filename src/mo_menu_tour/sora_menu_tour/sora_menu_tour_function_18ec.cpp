#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct V3 {
    float x, y, z;

    V3(const V3& p) : x(p.x), y(p.y), z(p.z) {}
    V3() {}
};

extern "C" {
extern const float lbl_3_rodata_8120;

void fn_3_18EC(u8* self, int* idx, u32 count, int v6) {
    u8* r8 = self;
    *(u32*)(self + 0xB90) = count;

    for (u32 i = 0; i < *(u32*)(self + 0xB90); i++, idx++, r8 += 4) {
        int v = *idx;
        *(int*)(r8 + 0xF14) = v;

        u8* e = self + v * 0x1C;
        u8* q = e + e[0xB94] * 2;
        u8 b = q[0xB95];
        u8 c = q[0xB96];
        V3 t;

        if (b == 0) {
            *(float*)(r8 + 0xF2C) = lbl_3_rodata_8120;
        } else {
            t = *(V3*)(*(u8**)(self + (b << 2) + 4) + 0x3C);
            *(float*)(r8 + 0xF2C) = t.x;
        }

        t = *(V3*)(*(u8**)(self + (c << 2) + 4) + 0x3C);
        *(float*)(r8 + 0xF3C) = t.x;
    }

    *(int*)(self + 0xF4C) = v6;
    *(int*)(self + 0xF24) = 0;
}
}
