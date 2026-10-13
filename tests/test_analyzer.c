#include <stdio.h>
#include <assert.h>
#include "../project/analyzer/analyzer.h"

int	main(void)
{
	int			nums_low[4] = {1, 2, 4, 3};   /* 1/6 = 16.67% -> < 20%  */
	int			nums_med[4] = {1, 3, 4, 2};   /* 2/6 = 33.33% -> < 50%  */
	int			nums_high[4] = {2, 4, 1, 3};  /* 3/6 = 50.00% -> >= 50% */
	t_config	cfg;
	t_analysis	res;

	/* 1. Adaptativo con desorden bajo (< 20%) -> Simple / O(n) */
	cfg.numbers = nums_low;
	cfg.size = 4;
	cfg.strategy = STRAT_ADAPTIVE;
	assert(analyze_input(&cfg, &res) == 1);
	assert(cfg.strategy == STRAT_SIMPLE);
	printf("Adaptativo (bajo):   %s / %s (disorder: %d)\n",
		res.strategy_name, res.complexity, res.disorder);

	/* 2. Adaptativo con desorden medio (20% - 50%) -> Medium / O(n√n) */
	cfg.numbers = nums_med;
	cfg.size = 4;
	cfg.strategy = STRAT_ADAPTIVE;
	assert(analyze_input(&cfg, &res) == 1);
	assert(cfg.strategy == STRAT_MEDIUM);
	printf("Adaptativo (medio):  %s / %s (disorder: %d)\n",
		res.strategy_name, res.complexity, res.disorder);

	/* 3. Adaptativo con desorden alto (>= 50%) -> Complex / O(nlogn) */
	cfg.numbers = nums_high;
	cfg.size = 4;
	cfg.strategy = STRAT_ADAPTIVE;
	assert(analyze_input(&cfg, &res) == 1);
	assert(cfg.strategy == STRAT_COMPLEX);
	printf("Adaptativo (alto):   %s / %s (disorder: %d)\n",
		res.strategy_name, res.complexity, res.disorder);

	/* 4. Estrategia manual fija -> Medium / O(n√n) sin sobreescribir nombre */
	cfg.numbers = nums_low;
	cfg.size = 4;
	cfg.strategy = STRAT_MEDIUM;
	assert(analyze_input(&cfg, &res) == 1);
	assert(cfg.strategy == STRAT_MEDIUM);
	printf("Manual (forzado):    %s / %s (disorder: %d)\n",
		res.strategy_name, res.complexity, res.disorder);

	return (0);
}
