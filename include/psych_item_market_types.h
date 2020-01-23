#ifndef PSYCH_ITEM_MARKET_TYPES_H
#define PSYCH_ITEM_MARKET_TYPES_H

#include "psych_mem.h"

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
  const char* name;
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
  const char* name;
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