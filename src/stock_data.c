#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    for (int i=0; i<stock_data->max_size; ++i) {
        int price_in_cents = rand() % 100 + 1;
        stock_data_add_entry(stock_data, price_in_cents);
    }
}

void stock_data_print_entries(StockDataArray* stock_data) {
    for (int i=0; i<stock_data->max_size; ++i) {
        printf("Price: %.2f at time: %ld\n", 
               stock_data->entries[i].price_in_cents / 100.0, 
               stock_data->entries[i].timestamp);
    }
}

int stock_data_add_entry(StockDataArray* stock_data, int price_in_cents) {
    StockDatum* entry = &stock_data->entries[stock_data->current];
    
    entry->price_in_cents = price_in_cents;
    entry->timestamp = time(NULL) + rand() % 10001;

    stock_data->current++;

    return 1;
}
