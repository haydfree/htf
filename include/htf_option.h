#ifndef HTF_OPTION_H
#define HTF_OPTION_H

#include <htf_base.h>

typedef struct Option
{
	void *val;
	b8 some;
} Option;

static inline Option htf_option_some(Type type, void *val)
{
	Option option = {0};
	option.val = val;
	option.some = TRUE;
	return option;
}

static inline Option htf_option_none(Type type, void *val)
{
	Option option = {0};
	option.val = val;
	option.some = FALSE;
	return option;
}

#define OPTION(type, val) do { if (val) { htf_option_some(type, val); } else { htf_option_none(type, val); } } while (0)

#endif
