#include "psych_item_market.h"

static int _psych_item_customers_init(psych_item_customer_t* custs, 
	                                  const psych_item_init_val_t* vals, size_t count)
{
	while(count--) {
		if (vals->value <= 0.0)
			return 0;
		custs->cash = vals->value;
		strncpy(custs->name, vals->name, PSYCH_ITEM_CUSTOMER_NAME_LEN);
		++vals;
		++custs;
	}
	return 1;
}

static int _psych_item_items_init(psych_item_item_t* items, 
	                                  const psych_item_init_val_t* vals, size_t count)
{
	while(count--) {
		if (vals->value <= 0.0)
			return 0;
		items->current_price = vals->value;
		strncpy(items->name, vals->name, PSYCH_ITEM_ITEM_NAME_LEN);
		++vals;
		++items;
	}
	return 1;
}

int psych_item_market_init(psych_item_market_t* market, unsigned votality,
	                       size_t customer_count, const psych_item_init_val_t* custs,
	                       size_t item_count, const psych_item_init_val_t* items)
{
	if (!votality || !customer_count || !item_count)
		return 0;
	market->turns = 0;
	market->votality = votality;
	market->item_count = item_count;
	market->customer_count = customer_count;
	_Psych_alloc(market->customers, (sizeof(psych_item_customer_t) * customer_count));
	_Psych_alloc(market->items, (sizeof(psych_item_item_t) * item_count));
	
	if(!_psych_item_customers_init(market->customers, custs, customer_count))
		return 0; // need cleanup of memory
	if(!_psych_item_items_init(market->items, items, item_count))
		return 0; // need cleanup of memory
	if (market->customers == NULL || market->items == NULL)
		return 0;
	if(!_psych_item_customers_init(market->customers, custs, customer_count))
		return 0;
	return 1;
}