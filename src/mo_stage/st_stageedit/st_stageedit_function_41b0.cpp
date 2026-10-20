#pragma force_active on
typedef unsigned int u32;

struct Object;

struct UpdateEntry {
    unsigned char data[0x24];
};

struct Entry {
    unsigned char data[0xc];
    Object* object;
    unsigned char tail[8];
};

struct Stage {
    unsigned char pad0[0x1e6];
    unsigned char updateCount;
    unsigned char pad1[0xd];
    UpdateEntry* updates;
    Object** objectsA;
    Object** objectsB;
    u32* masksA;
    u32* masksB;
    unsigned char pad2[0xb4];
    int timer;
    int entryCount;
    unsigned char pad3[0x10];
    u32 countA;
    u32 countB;
    unsigned char pad4[0x218];
    Entry entries[1];
};

extern "C" {
void fn_85_487C(Stage*, UpdateEntry*, float);
void fn_8011176C(Object*, int);
void fn_801117A4(Object*, int);
void fn_801112FC(Object*, Object*);
void fn_8011135C(Object*, Object*);

void fn_85_41B0(Stage* self, float delta) {
    u32 updateCount = self->updateCount;
    if (updateCount && self->updates) {
        for (u32 i = 0; i < updateCount; ++i) {
            fn_85_487C(self, &self->updates[i], delta);
        }
    }

    if (self->timer > 0) {
        if (--self->timer == 0) {
            int count = self->entryCount;
            Entry* entries = self->entries;
            Object* object;
            for (int i = 0; i < count; ++i, ++entries) {
                object = entries->object;
                if (object) {
                    fn_8011176C(object, 0);
                    fn_801117A4(object, 0);
                }
            }
        }
    } else {
        u32 countA = self->countA;
        u32 countB = self->countB;
        Object** objectsA = self->objectsA;
        Object** objectsB = self->objectsB;
        u32* masksA = self->masksA;
        u32* masksB = self->masksB;

        if (!objectsA || !masksA) countA = 0;
        if (!objectsB || !masksB) countB = 0;

        if (countA) {
            for (u32 i = 0; i < countA; ++i) {
                Object* object = objectsA[i];
                if (object) fn_801117A4(object, 1);
            }

            for (u32 i = 0; i < countA; ++i) {
                Object* object = objectsA[i];
                if (object) {
                    u32 mask = masksA[i];
                    for (u32 j = i + 1; j < countA; ++j) {
                        Object* other = objectsA[j];
                        if (other && object != other) {
                            u32 common = mask & masksA[j];
                            if ((common & 0x3ffff) && (common & 0xfffc0000)) {
                                fn_801112FC(object, other);
                                fn_801112FC(other, object);
                                fn_8011135C(object, other);
                                fn_8011135C(other, object);
                            }
                        }
                    }
                }
            }

            for (u32 i = 0; i < countB; ++i) {
                Object* object = objectsB[i];
                if (object) {
                    fn_801117A4(object, 1);
                    u32 mask = masksB[i];
                    for (u32 j = 0; j < countA; ++j) {
                        Object* other = objectsA[j];
                        if (other) {
                            u32 common = mask & masksA[j];
                            if ((common & 0x3ffff) && (common & 0xfffc0000)) {
                                fn_801112FC(object, other);
                                fn_801112FC(other, object);
                                fn_8011135C(object, other);
                                fn_8011135C(other, object);
                            }
                        }
                    }
                    fn_801117A4(object, 0);
                }
            }

            for (u32 i = 0; i < countA; ++i) {
                Object* object = objectsA[i];
                if (object) fn_801117A4(object, 0);
            }
        }
    }
}
}
