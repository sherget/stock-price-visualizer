#include "stock_data.h"

const int NUMBER_OF_ENTRIES = 20;

int main() {
    StockDataArray* data = stock_data_create(NUMBER_OF_ENTRIES);
    stock_data_generate_dummy_data(data);
    stock_data_print_entries(data);
}

