#include "unit_test_helpers.h"
#include "psych_item_market.h"

static const psych_item_init_val_t ITEM_LST1[] = {
	{5.4, "apple"}
};


static void test_psych_item_market_init(void)
{

}

int main(int argc, char const *argv[])
{
	test_psych_item_market_init();
	RETURN_FAILURES
}