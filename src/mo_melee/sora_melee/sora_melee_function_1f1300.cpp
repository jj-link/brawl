#pragma force_active on
extern "C" float lbl_27_rodata_2BA4;

struct Entry {
    unsigned char pad0[0x18];
    float left;
    float leftY;
    float right;
    float rightY;
    float height;
    unsigned char pad2C[0x14];
    unsigned int flags;
    unsigned char pad44[8];
};

struct State {
    unsigned char pad0[0x34C];
    Entry* entries;
    unsigned short count;
};

extern "C" int fn_27_1F1300(State* self, const float* pos, float slope) {
    int count = self->count;
    Entry* entry = self->entries;
    float epsilon = lbl_27_rodata_2BA4;
    for (; count > 0; --count, ++entry) {
        if (entry->flags & 2) {
            float height = entry->height;
            float y = pos[1];
            if (!(height > y)) {
                float left = entry->left;
                float x = pos[0];
                if (left > x) {
                    if (slope > epsilon) {
                        if (y - entry->leftY > (left - x) / slope)
                            return 1;
                    } else if (y > entry->leftY) {
                        return 1;
                    }
                } else {
                    float right = entry->right;
                    if (right < x) {
                        if (slope > epsilon) {
                            if (y - entry->rightY > (x - right) / slope)
                                return 1;
                        } else if (y > entry->rightY) {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
