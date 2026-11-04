#include <gr/gr_gimmick.h>
#pragma force_active on

struct SoundFrame { unsigned int index; float start; float end; };
struct FrameList { SoundFrame* frames; unsigned int count; };
struct SoundEntry { char pad[8]; int handle; char rest[0x1c]; };
struct ObjectData { char pad[0xa4]; unsigned int count; SoundEntry* sounds; char pad2[0xa4]; FrameList* lists; unsigned int listCount; float frame; };
extern "C" const float lbl_27_rodata_45AC;

extern "C" void fn_27_27C208(grGimmick* self, unsigned int index, float frame) {
    ObjectData* data = (ObjectData*)self;
    if (data->listCount > index && data->frame != frame) {
        FrameList* list = &data->lists[index];
        SoundFrame* p = list->frames;
        if (p) {
            unsigned int count = list->count;
            unsigned int once = 0, active = 0, loops = 0;
            for (unsigned int i = 0; i < count; ++i, ++p) {
                if (lbl_27_rodata_45AC == p->end) {
                    float prev = data->frame;
                    float start = p->start;
                    bool hit;
                    if (prev <= frame)
                        hit = prev < start && start <= frame;
                    else
                        hit = prev < start || start <= frame;
                    if (hit)
                        once |= 1 << p->index;
                } else {
                    float prev = data->frame;
                    float start = p->start;
                    float end = p->end;
                    bool hit;
                    if (prev <= frame)
                        hit = (prev < start && start <= frame) ||
                              (prev < end && end <= frame) ||
                              (start < prev && prev < end) ||
                              (start <= frame && frame <= end);
                    else
                        hit = (start < prev && prev < end) ||
                              (start <= frame && frame <= end);
                    if (hit)
                        active |= 1 << p->index;
                    loops |= 1 << p->index;
                }
            }
            SoundEntry* sound = data->sounds;
            unsigned int i = 0;
            unsigned int mask = 1;
            unsigned int n = data->count;
            for (; i < n; mask <<= 1, ++sound, ++i) {
                if (loops & mask) {
                    if (active & (1 << i)) {
                        if (sound->handle == -1)
                            self->startGimmickSE(i);
                    } else if (sound->handle != -1)
                        self->stopGimmickSE(i);
                } else if (once & mask)
                    self->startGimmickSE(i);
            }
            data->frame = frame;
        }
    }
}