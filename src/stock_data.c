#include <stdio.h>
#include <stdlib.h>
#include "stock_data.h"

StockDataArray* stock_data_create(int n) {
    StockDataArray* data = (StockDataArray*) malloc(sizeof(StockDataArray) + n * sizeof(StockDatum));
    if (data == NULL) {
        fprintf(stderr, "Error allocating memory for StockData array\n");
        return NULL; 
    }

    data->current = 0;
    data->max_size = n;

    return data;
}

void stock_data_free(StockDataArray* stock_data) {
    free(stock_data);
}

void stock_data_generate_dummy_data(StockDataArray* stock_data) {
}

void stock_data_print_entries(StockDataArray* stock_data) {
}

int stock_data_add_entry(StockDataArray* stock_data, int price_in_cents) {
    return 1;
}
