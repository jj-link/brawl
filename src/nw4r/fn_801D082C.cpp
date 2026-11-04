#include <revolution/OS/OSInterrupt.h>
#pragma force_active on
extern float lbl_805A3640;
extern float lbl_805A3644;
extern "C" {
void fn_801BA210(void*, int, float);
void fn_802022DC(void*, int);
unsigned char* fn_801B77F8();
void fn_801BA8F0(void*);
}
extern "C" void fn_801D082C(void* arg0) {
    unsigned char* self = (unsigned char*)arg0;
    int enabled = OSDisableInterrupts();
    int j;
    int pauseJ;
    int resumeJ;
    int updateJ;
    int i;
    int k;
    int pauseI;
    int resumeI;
    int updateI;
    int offset;
    unsigned char* secondEntry;
    unsigned char* pauseEntry;
    unsigned char* resumeEntry;
    unsigned char* updateRow;
    unsigned char* channel;
    unsigned char* row;
    unsigned char* pauseRow;
    unsigned char* resumeRow;
    unsigned char* updateEntry;
    if (!self[0xAC]) {
        OSRestoreInterrupts(enabled);
        return;
    }
    if ((self[0xB1] & 1) && self[0xAD] && !self[0xAE]) {
        float lower;
        float upper = lbl_805A3640;
        channel = self;
        lower = lbl_805A3644;
        i = 0;
        offset = 0;
        while (i < *(int*)(self + 0xA0)) {
            float value = *(float*)(channel + 0x30);
            if (value > upper) value = upper;
            else if (value < lower) value = lower;
            unsigned char* entry = self + offset;
            j = 0;
            float volume = *(float*)(self + 0x10C) * value;
            while (j < *(int*)(self + 0x9C)) {
                void* sound = *(void**)(entry + 0xC);
                if (sound) fn_801BA210(sound, 1, volume);
                entry += 0x10;
                ++j;
            }
            channel += 0x1C;
            offset += 4;
            ++i;
        }
        row = self;
        j = 0;
        while (j < *(int*)(self + 0x9C)) {
            secondEntry = row;
            k = 0;
            while (k < *(int*)(self + 0xA0)) {
                void** sound = *(void***)(secondEntry + 0xC);
                if (sound && *sound) fn_802022DC(*sound, 1);
                secondEntry += 4;
                ++k;
            }
            row += 0x10;
            ++j;
        }
        self[0xAE] = 1;
        self[0xB1] &= ~1;
        self[0xB1] &= ~4;
    }
    if (self[0xAE]) {
        if ((self[0xB1] & 2) && self[0xAD]) {
            if (self[0xAF] || fn_801B77F8()[0x1A]) {
                pauseRow = self;
                pauseJ = 0;
                while (pauseJ < *(int*)(self + 0x9C)) {
                    pauseEntry = pauseRow;
                    pauseI = 0;
                    while (pauseI < *(int*)(self + 0xA0)) {
                        unsigned char** sound = *(unsigned char***)(pauseEntry + 0xC);
                        if (sound) {
                            unsigned char* inner = *sound;
                            int active = 0;
                            if (inner && *(unsigned short*)(inner + 0x38) == 1) active = 1;
                            if (active) fn_802022DC(inner, 0);
                        }
                        pauseEntry += 4;
                        ++pauseI;
                    }
                    pauseRow += 0x10;
                    ++pauseJ;
                }
                self[0xB0] = 1;
            } else {
                resumeRow = self;
                resumeJ = 0;
                while (resumeJ < *(int*)(self + 0x9C)) {
                    resumeEntry = resumeRow;
                    resumeI = 0;
                    while (resumeI < *(int*)(self + 0xA0)) {
                        void** sound = *(void***)(resumeEntry + 0xC);
                        if (sound && *sound) fn_802022DC(*sound, 1);
                        resumeEntry += 4;
                        ++resumeI;
                    }
                    resumeRow += 0x10;
                    ++resumeJ;
                }
                self[0xB0] = 0;
            }
            self[0xB1] &= ~2;
        }
        updateRow = self;
        updateJ = 0;
        while (updateJ < *(int*)(self + 0x9C)) {
            updateEntry = updateRow;
            updateI = 0;
            while (updateI < *(int*)(self + 0xA0)) {
                void* sound = *(void**)(updateEntry + 0xC);
                if (sound) fn_801BA8F0(sound);
                updateEntry += 4;
                ++updateI;
            }
            updateRow += 0x10;
            ++updateJ;
        }
    }
    OSRestoreInterrupts(enabled);
}
