struct MarioParameterRecord {
    unsigned char prefix[8];
    int field08;
    int field0C;
    int field10;
    unsigned short field14;
    unsigned short field16;
};
extern "C" {
int fn_91_102D8(MarioParameterRecord* record) { return record->field10; }
int fn_91_102E0(MarioParameterRecord* record) { return record->field10; }
int fn_91_102E8(MarioParameterRecord* record) { return record->field10; }
unsigned short fn_91_102F0(MarioParameterRecord* record) { return record->field14; }
int fn_91_102F8(MarioParameterRecord* record) { return record->field08; }
unsigned short fn_91_10300(MarioParameterRecord* record) { return record->field16; }
int fn_91_10308(MarioParameterRecord* record) { return record->field0C; }
void fn_91_10310(MarioParameterRecord* record, unsigned short value) { record->field16 = value; }
void fn_91_10318(MarioParameterRecord* record, unsigned short value) { record->field14 = value; }
void fn_91_10320(MarioParameterRecord* record, int value) { record->field0C = value; }
void fn_91_10328(MarioParameterRecord* record, int value) { record->field08 = value; }
void fn_91_10330(MarioParameterRecord* record, int value) { record->field10 = value; }
}
