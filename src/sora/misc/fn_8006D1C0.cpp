#pragma force_active on
namespace ms {
class CharWriter;
}
struct Record { unsigned char c[4]; float x, y; unsigned char flags; };
struct Object { char pad[12]; Record entries[8]; };

extern "C" void GetTextColor__Q22ms10CharWriterCFv(unsigned char* out, const ms::CharWriter* self);
extern "C" float GetScaleH__Q22ms10CharWriterCFv(const ms::CharWriter* self);
extern "C" float GetScaleV__Q22ms10CharWriterCFv(const ms::CharWriter* self);

extern "C" int fn_8006D1C0(unsigned char* self, ms::CharWriter** arg1, unsigned char flags) {
    if (*(int*)(self + 8) >= 8) {
        *(int*)(self + 8) = 7;
        Object* obj = (Object*)(self + 0x10);
        for (int i = 0; i < 7; i++) {
            obj->entries[i - 1] = obj->entries[i];
        }
    }

    unsigned char* rec = self + (*(int*)(self + 8) << 4);
    ms::CharWriter* temp_r28 = *arg1;
    rec[0x18] = flags;

    if (flags & 2) {
        unsigned char c[4];
        GetTextColor__Q22ms10CharWriterCFv(c, temp_r28);
        rec[0xC] = c[0];
        rec[0xD] = c[1];
        rec[0xE] = c[2];
        rec[0xF] = c[3];
    }
    if (flags & 1) {
        *(float*)(rec + 0x10) = GetScaleH__Q22ms10CharWriterCFv(temp_r28);
        *(float*)(rec + 0x14) = GetScaleV__Q22ms10CharWriterCFv(temp_r28);
    }
    if (flags & 0x80) {
        self[4] = 1;
    }
    *(int*)(self + 8) = *(int*)(self + 8) + 1;
    return 1;
}
