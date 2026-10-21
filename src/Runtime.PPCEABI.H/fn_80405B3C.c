#pragma force_active on
typedef struct DBCommTable {
    char pad[0x24];
    void (*fn24)(void*);
} DBCommTable;

extern DBCommTable gDBCommTable;

void ReserveEXI2Port(void) {
    gDBCommTable.fn24(&gDBCommTable);
}
