#ifndef PSYCH_ITEM_MARKET_H
#define PSYCH_ITEM_MARKET_H

#include "psych_item_market_types.h"

int psych_item_market_init(psych_item_market_t* market, unsigned votality,
	                       size_t customer_count, const psych_item_init_val_t* custs,
	                       size_t item_count, const psych_item_init_val_t* items);

#endif // PSYCH_ITEM_MARKEt_H