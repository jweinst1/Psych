#include "psych_item_market.h"

int psych_item_market_init(psych_item_market_t* market, unsigned votality,
	                       size_t customer_count, const psych_item_init_val_t* custs,
	                       size_t item_count, const psych_item_init_val_t* items)
{
	if (!votality) // votality must be 1 or greater
		return 0;
	market->turns = 0;
	market->votality = votality;
	market->item_count = item_count;
	market->customer_count = customer_count;
	_Psych_alloc(market->customers, (sizeof(psych_item_customer_t) * customer_count));
	_Psych_alloc(market->items, (sizeof(psych_item_item_t) * item_count));
	// need init of customers and items . todo
	if (market->customers == NULL || market->items == NULL)
		return 0;
	return 1;
}