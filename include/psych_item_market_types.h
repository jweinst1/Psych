#ifndef PSYCH_ITEM_MARKET_TYPES_H
#define PSYCH_ITEM_MARKET_TYPES_H

#include "psych_mem.h"

#ifndef PSYCH_ITEM_CUSTOMER_NAME_LEN
#define PSYCH_ITEM_CUSTOMER_NAME_LEN 25
#endif

#ifndef PSYCH_ITEM_ITEM_NAME_LEN
#define PSYCH_ITEM_ITEM_NAME_LEN 25
#endif

struct psych_item_customer_t;
struct psych_item_item_t;

typedef struct {
	struct psych_item_customer_t* customer;
	struct psych_item_item_t* item;
	double price;
	double amount;
} psych_item_order_t;

typedef struct {
  psych_item_order_t* orders;
  size_t len;
  size_t cap;
} psych_item_order_queue_t;

typedef struct {
  char name[PSYCH_ITEM_ITEM_NAME_LEN + 1];
  double current_price;
  psych_item_order_queue_t buys;
  psych_item_order_queue_t sells;
} psych_item_item_t;

typedef struct {
	psych_item_item_t* item;
	double cost_basis;
	double amount;
} psych_item_position_t;

typedef struct {
  psych_item_position_t* pos;
  size_t len;
  size_t cap;
} psych_item_positions_t;

typedef struct {
  double cash;
  char name[PSYCH_ITEM_CUSTOMER_NAME_LEN + 1];
  psych_item_positions_t posts;
} psych_item_customer_t;

typedef struct {
  psych_item_item_t* items;
  size_t item_count;
  psych_item_customer_t* customers;
  size_t customer_count;
  unsigned votality;
  size_t turns;
} psych_item_market_t;

/// Init Help Types ////

typedef struct {
	double value;
	const char* name;
} psych_item_init_val_t;

#endif // PSYCH_ITEM_MARKET_TYPES_H