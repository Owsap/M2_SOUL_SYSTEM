/// 1.
// Search
	else if (p->type == REFINE_TYPE_MONEY_ONLY)

// Add above
#if defined(__SOUL_SYSTEM__)
	else if (p->type == REFINE_TYPE_SOUL_AWAKE || p->type == REFINE_TYPE_SOUL_EVOLVE)
	{
		ch->DoRefineSoul(item);
	}
#endif
