#ifndef STOCK_DATA_H
#define STOCK_DATA_H

#include <time.h>

typedef struct {
    int price_in_cents;
    time_t timestamp;
} StockDatum;

typedef struct {
    int current;
    int max_size;
    StockDatum entries[]; 
} StockDataArray;

StockDataArray* stock_data_create(int n);
void stock_data_free(StockDataArray* stock_data);
int stock_data_add_entry(StockDataArray* stock_data, int price);
void stock_data_generate_dummy_data(StockDataArray* stock_data);
void stock_data_print_entries(StockDataArray* stock_data);

#endif // !STOCK_DATA_H
